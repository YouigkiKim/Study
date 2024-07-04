fn main() {
    println!("He!");
    let seo = 32.12;
    let moon = 12;
    let bae = 17.12122121;
    let b = seo + moon as f64 + bae ;
    let x = 32;
    println!("{}fku",b);
    let num = [1,2,3];
    println!("{}{:?}",x,num);

    //선언문 안의 조건문
    let condition = true;
    let mut number = if condition {
        5
    } else {
        6
    };
    println!("The value of number is: {}", number);

    //while문
    while number != 0 {
        println!("{}!", number);

        number = number - 1;
    }

    println!("LIFTOFF!!!");

    //.rev() >> reverse
    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!!!");

    for y in  11..20 {
        println!("");
        println!("{}단",y);
        for x in  11..19 {
            println!("{}*{}={}",y,x,x*y);
        }
    }
}
