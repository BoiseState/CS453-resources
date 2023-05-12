// Rust sum program

fn sum(seq: &[i32]) -> i32 {
  let mut s=0;
  for v in seq.iter() {
    s+=v;
  }
  s
}

fn main() {
  let seq=[5,6,1,8,3,7];
  println!("{}",sum(&seq));
}
