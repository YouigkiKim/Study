fn main(){
    println!("ㅁㄴ에러");
    //배열에서 변수형과 길이 설정 
    let nms: [i32;3] = [1,2,3];
    // 기본 배열설정
    let nums2 = [1,2,3,4];
    println!("{:?}",nums2);
    println!("{}",nms[0]);
    println!("{}",nms[2]); // 2는 0 1 2 세번째 배열
    println!("{}", add(1,2));
    let nums =  swap(1,2);
    println!("{:?}",nums); //  {:?}는 디버그 트레이트, 대부분의 포맷을 알아서 출력해줌
    let x= 62i64;

    // if문
    if x < 40{
        println!("{}",x);

    } else if x == 40{
        println!("{}",x);
    } else{
        println!("x는 {}",x);
    }

    //가변변수 설정 mut
    let mut x = 0;

    //loop문
    loop {
        println!("{}",x);
        x += 1;
        if x == 5{
            break;
        }
    }
    for x in 0..5{
        println!("{}",x);
        for _x in 0..=2{
            println!("에베베")
        }
    }
    //match함수
    x=0;
    match x {
        0 => {
            println!("{}",x);
        }
        1|2 => {
            println!("1이나2");
        }
        3..=9 => {
            println!("3~9");
        }
        matched_num @ 10..=100 => {
            println!("찾은 수: {}",matched_num);
        }
        _ => {
            // 어떤 케이스에도 해당하지 않을 때 사용하는 함수
            println!("어느 케이스에도 해당하지 않을 때기본으로 존재해야하는 ")
        }
    }

    //loop문에 변수할당
    x=0;
    let v = loop {
        x += 1;
        if x == 13 {
            break "13 찾았다";
        }
    };
    println!("loop에서: {}", v);
}

//기본 덧셈함수, 함수의 기본문법
fn add(x: i32, y: i32) -> i32 {
    let z= x*y;
    return (x+y)*z;
}

fn swap(x: i32, y:i32) -> (i32,i32){
    println!("{}{}",y,x);
    return (y,x);
}

// 개별 코드 컴파일하는 방법
// rustc filename.rs > 컴파일된 파일 생성
// ./filename