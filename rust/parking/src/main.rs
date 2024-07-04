// //Input을 입력받기 위해 사용하는 std::io라이브러리
// use std::io;

// //문자열을 정수형으로 바꿔서 push하는 함수
// fn to_int(input: &String) -> Result<i32, String> {
//     match input.trim().parse::<i32>() {
//         Ok(num) => Ok(num),
//         Err(_) => Err("정수형이 아닙니다.".to_string())
//     }
// }

// //number만큼의 수를 저장하는 함수
// fn save(numbers: &mut Vec<i32>,number: i32) {
//     for i in 0..number {
//         println!("{}번째 숫자를 입력하세요!",i+1);
//         let mut input_save = String::new();
//         io::stdin().read_line(&mut input_save).expect("입력을 읽는데 실패했습니다.");

//         match to_int(&input_save){
//             Ok(num) => numbers.push(num),
//             Err(e) => println!("{}",e)
//         }
//     }
// }

// fn main() {
//     let mut numbers : Vec<i32> = Vec::new();
//     let mut input :String = String::new();

//     println!("몇 개의 숫자를 저장하나요?");
//     io::stdin().read_line(&mut input).expect("입력을 읽는데 실패했습니다.");

//     let  number: i32 = to_int(&input).expect("정수형 변환에 실패했습니다.");
//     save(&mut numbers,number);

//     for i in 0..numbers.len(){
//         println!("{}", numbers[i]);
//     }
// }

//Input을 입력받기 위해 사용하는 std::io라이브러리
use std::io;

// 문자열을 정수형으로 바꿔서 push하는 함수
fn to_int(input: &String) -> Result<i32, String> {
    match input.trim().parse::<i32>() {
        Ok(num) => Ok(num),
        Err(_) => Err("정수형이 아닙니다.".to_string())
    }
}

// 숫자와 위치를 저장하는 구조체
struct NumberPosition {
    number: i32,
    position: usize,
}

// 숫자와 위치를 저장하는 함수
fn save(numbers: &mut Vec<i32>, number: i32) -> Vec<NumberPosition> {
    let mut saved_numbers = Vec::new();
    for (i, _) in (0..number).enumerate() {
        println!("{}번째 숫자를 입력하세요!", i + 1);
        let mut input_save = String::new();
        io::stdin().read_line(&mut input_save).expect("입력을 읽는데 실패했습니다.");

        match to_int(&input_save) {
            Ok(num) => {
                numbers.push(num);
                saved_numbers.push(NumberPosition { number: num, position: i });
            }
            Err(e) => println!("{}", e)
        }
    }
    saved_numbers
}

// 메뉴 선택 기능을 담당하는 함수
fn select_menu() -> i32 {
    println!("------------------------------");
    println!("원하는 기능을 선택하세요:");
    println!("1. 숫자 저장하기");
    println!("2. 저장된 숫자의 위치 출력하기");
    println!("3. 종료하기");
    println!("------------------------------");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("입력을 읽는데 실패했습니다.");

    match to_int(&input) {
        Ok(choice) => choice,
        Err(_) => {
            println!("잘못된 선택입니다.");
            select_menu()
        }
    }
}

fn main() {
    let mut numbers: Vec<i32> = Vec::new();
    let mut saved_positions: Vec<NumberPosition> = Vec::new();

    loop {
        let choice = select_menu();

        match choice {
            1 => {
                println!("몇 개의 숫자를 저장하나요?");
                let mut input = String::new();
                io::stdin().read_line(&mut input).expect("입력을 읽는데 실패했습니다.");
                let number: i32 = match to_int(&input) {
                    Ok(num) => num,
                    Err(_) => {
                        println!("올바른 숫자를 입력하세요.");
                        continue;
                    }
                };
                saved_positions = save(&mut numbers, number);
            }
            2 => {
                println!("어떤 숫자의 위치를 찾으시겠습니까?");
                let mut input = String::new();
                io::stdin().read_line(&mut input).expect("입력을 읽는데 실패했습니다.");
                let search_number: i32 = match to_int(&input) {
                    Ok(num) => num,
                    Err(_) => {
                        println!("올바른 숫자를 입력하세요.");
                        continue;
                    }
                };
                let mut found = false;
                for pos in saved_positions.iter() {
                    if pos.number == search_number {
                        println!("숫자 {}는 {}번째 위치에 저장되었습니다.", pos.number, pos.position + 1);
                        found = true;
                        break;
                    }
                }
                if !found {
                    println!("입력하신 숫자가 저장된 정보에 없습니다.");
                }
            }
            3 => {
                println!("프로그램을 종료합니다.");
                break;
            }
            _ => println!("잘못된 선택입니다."),
        }
    }
}