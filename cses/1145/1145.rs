pub mod solution {
    use super::io::{InputReader, OutputWriter};

    pub fn solve<R: std::io::Read, W: std::io::Write>(
        reader: &mut InputReader<R>,
        writer: &mut OutputWriter<W>,
    ) {
        let n: usize = reader.next();

        let mut dp: Vec<u32> = vec![];
        for _ in 0usize..n {
            let x = reader.next();

            let pp = dp.partition_point(|&item| item < x);
            if pp == dp.len() {
                dp.push(x);
            } else {
                dp[pp] = x;
            }
        }

        writer.println(dp.len());
    }
}

mod io {
    /*
      Author: Axel Lindeberg, github.com/AxlLind
      Repository: https://github.com/AxlLind/easy_io
      License: MIT
      2020
    */
    use std::fmt::Display;
    use std::fs::{File, OpenOptions};
    use std::io::{self, Read, Result, Stdin, Stdout, Write};

    const EOF: &str = "InputReader: Reached end of input!";

    pub struct InputReader<R: Read> {
        reader: R,
        buf: Vec<u8>,
        bytes_read: usize,
        current_index: usize,
    }

    impl InputReader<Stdin> {
        pub fn new() -> Self {
            Self::from_reader(io::stdin())
        }
    }

    impl InputReader<File> {
        pub fn from_file(path: &str) -> Self {
            Self::from_reader(File::open(path).unwrap())
        }
    }

    impl<R: Read> InputReader<R> {
        pub fn from_reader(reader: R) -> Self {
            Self {
                reader,
                buf: vec![0; 1 << 16],
                bytes_read: 0,
                current_index: 0,
            }
        }

        pub fn next<T: InputReadable>(&mut self) -> T {
            T::from_input(self)
        }

        pub fn next_line(&mut self) -> String {
            assert!(self.has_more(), "{}", EOF);
            let mut line = String::new();
            while self.peek() != '\n' {
                line.push(self.peek());
                self.consume();
                if !self.has_more() {
                    break;
                }
            }
            self.consume(); // consume '\n'
            line
        }

        pub fn has_more(&mut self) -> bool {
            if self.current_index >= self.bytes_read {
                self.bytes_read = self.reader.read(&mut self.buf[..]).unwrap();
                self.current_index = 0
            }
            self.bytes_read > 0
        }

        pub fn set_buf_size(&mut self, buf_size: usize) {
            self.buf.resize(buf_size, 0);
        }

        fn peek(&self) -> char {
            self.buf[self.current_index] as char
        }

        fn consume(&mut self) {
            self.current_index += 1;
        }

        fn pop_digit(&mut self) -> u64 {
            let c = self.peek();
            self.consume();
            c as u64 - '0' as u64
        }

        fn consume_until<F: Fn(char) -> bool>(&mut self, test: F) {
            loop {
                assert!(self.has_more(), "{}", EOF);
                if test(self.peek()) {
                    return;
                }
                self.consume();
            }
        }

        fn consume_until_sign(&mut self) -> i64 {
            loop {
                self.consume_until(|c| c.is_ascii_digit() || c == '-');
                if self.peek() != '-' {
                    return 1;
                }

                self.consume();
                assert!(self.has_more(), "{}", EOF);
                if self.peek().is_ascii_digit() {
                    return -1;
                }
            }
        }
    }

    pub trait InputReadable {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self;
    }

    impl InputReadable for u64 {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
            input.consume_until(|c| c.is_ascii_digit());
            let mut num = 0;
            while input.peek().is_ascii_digit() {
                num = num * 10 + input.pop_digit();
                if !input.has_more() {
                    break;
                }
            }
            num
        }
    }

    impl InputReadable for i64 {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
            let sign = input.consume_until_sign();
            u64::from_input(input) as i64 * sign
        }
    }

    impl InputReadable for f64 {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
            let sign = input.consume_until_sign() as f64;
            let mut num = 0.0;
            while input.peek().is_ascii_digit() {
                num = num * 10.0 + input.pop_digit() as f64;
                if !input.has_more() {
                    break;
                }
            }

            let mut factor = 1.0;
            if input.peek() == '.' {
                input.consume();
                while input.has_more() && input.peek().is_ascii_digit() {
                    num = num * 10.0 + input.pop_digit() as f64;
                    factor *= 10.0;
                }
            }
            sign * num / factor
        }
    }

    impl InputReadable for String {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
            input.consume_until(|c| c.is_ascii_graphic());
            let mut word = String::new();
            while input.peek().is_ascii_graphic() {
                word.push(input.peek());
                input.consume();
                if !input.has_more() {
                    break;
                }
            }
            word
        }
    }

    impl InputReadable for char {
        fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
            input.consume_until(|c| c.is_ascii_graphic());
            let c = input.peek();
            input.consume();
            c
        }
    }

    macro_rules! impl_readable_from {
  ($A:ty, [$($T:ty),+]) => {
    $(impl InputReadable for $T {
      fn from_input<R: Read>(input: &mut InputReader<R>) -> Self {
        <$A>::from_input(input) as $T
      }
    })+
  };
}
    impl_readable_from! { u64, [u32, u16, u8, usize] }
    impl_readable_from! { i64, [i32, i16, i8, isize] }
    impl_readable_from! { f64, [f32] }

    pub struct OutputWriter<W: Write> {
        writer: W,
        buf: Vec<u8>,
    }

    impl OutputWriter<Stdout> {
        pub fn new() -> Self {
            Self::from_writer(io::stdout())
        }
    }

    impl OutputWriter<File> {
        pub fn from_file(path: &str) -> Self {
            let file = OpenOptions::new().write(true).create(true).open(path);
            Self::from_writer(file.unwrap())
        }
    }

    impl<W: Write> OutputWriter<W> {
        pub fn from_writer(writer: W) -> Self {
            let buf = Vec::with_capacity(1 << 16);
            Self { writer, buf }
        }

        pub fn print<T: Display>(&mut self, t: T) {
            write!(self, "{}", t).unwrap();
        }

        pub fn prints<T: Display>(&mut self, t: T) {
            write!(self, "{} ", t).unwrap();
        }

        pub fn println<T: Display>(&mut self, t: T) {
            writeln!(self, "{}", t).unwrap();
        }
    }

    impl<W: Write> Write for OutputWriter<W> {
        fn write(&mut self, bytes: &[u8]) -> Result<usize> {
            self.buf.extend(bytes);
            Ok(bytes.len())
        }

        fn flush(&mut self) -> Result<()> {
            self.writer.write_all(&self.buf)?;
            self.writer.flush()?;
            self.buf.clear();
            Ok(())
        }
    }

    impl<W: Write> Drop for OutputWriter<W> {
        fn drop(&mut self) {
            self.flush().unwrap();
        }
    }
}

pub fn main() {
    use crate::io::{InputReader, OutputWriter};
    solution::solve(&mut InputReader::new(), &mut OutputWriter::new());
}
