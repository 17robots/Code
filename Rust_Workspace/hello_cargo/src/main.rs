use std::io;

fn main() {
    println!("Welcome to the Guesing Game");
    println!("Please Enter Your Guess");

    let mut guess = String::new();

    io::stdin().read_line(&mut guess).expect("Failed to read line");

    println!("You guessed {}", guess);
}
