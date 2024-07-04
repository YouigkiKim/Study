use std::io;

//3
struct Rectangle{
    width: f64,
    height: f64,
}
impl Rectangle{
    fn area(&self) -> f64 {
        self.width*self.height
    }
}
enum Calculator{
    Add(i32,i32),
    Subtract(i32,i32),
    Multiply(i32,i32)
}
impl Calculator{
    fn calculator(&self) -> i32 {
        match self{
            Calculator::Add(a,b) => a+b,
            Calculator::Subtract(a,b ) => a-b,
            Calculator::Multiply(a,b ) => a*b 
        }
    }
}
//4
fn print_sign(num: i32){
    if num>= 0 {
        println!("+");
    }
    else if num < 0{
        println!("-");
    }
    else{
        println!("0");
    }
}

fn main() {
    // 1-1
    let name = "Alice";
    println!("Hello, {}",name);
    // 1-2
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("실패");
    let numbers: Vec<&str> = input.trim().split_ascii_whitespace().collect();
    let result: i32;
    if numbers.len() >= 2{
        let num1: i32 = numbers[0].parse().expect("1실패");
        let num2: i32 = numbers[1].parse().expect("2failure");
        result = num1+num2;
        println!("두 수의 합 = {}",result);
    }
    else{
        println!("두 정수가 아님");
    }
    
    // 2
    let rect = Rectangle{
        width: 5.0,
        height:10.0};
    println!("사각형의 넓이: {}",rect.area());
    let add_result = Calculator::Add(10,8);
    let subtract_result = Calculator::Subtract(10, 8);
    let mulitply_result = Calculator::Multiply(10, 8);
    println!("더하기 뺴기 곱하기 {},{},{}",add_result.calculator(),subtract_result.calculator(),mulitply_result.calculator());
    // 3
    print_sign(8);
    print_sign(0);
    print_sign(-5);
}

