use std::io;
fn main() {
    println!("guess the number!");
    println!("Please input your guess.");
    let mut guess = String::new();
    io::stdin().read_line(&mut guess)
        .expect("Failed to read line");
    println!("you guessed: {}",guess);
    let t: bool = true;
    let f: bool = false;
}
