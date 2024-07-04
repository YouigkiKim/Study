//구조체로 학생의 이름, 학번, 성적 세개 를 관리
//Bob의 학번을 출력하기
//James의 평균성적을 구해보기 (메소드 사용 X)
//method를 구현해 Kyungho 의 평균성적을 구해보기



// Bob의 학생 정보: 이름은 Bob, 학번은 12345, 성적은 [90, 85, 95]

// James의 학생 정보: 이름은 James, 학번은 32412, 성적은 [50, 85, 55]

// Kyungho의 학생 정보: 이름은 Kyungho, 학번은 32325, 성적은 [90, 75, 45]


struct Student {                        //Student structure 선언
    // ?
    name: String,
    // ?
    stid: u32,
    // ?
    grade: Vec<f64>
}


impl Student {                          //Student가 가지는 method 선언
    // ?  
    fn avg(&self) -> f64 {
        (self.grade[0]+self.grade[1]+self.grade[2]) /3.0
    }

}


fn main() {                             //본격적으로 코드가 동작하는 공간


    let student1 = Student {    //student1을 Student struct를 통해 만들기 , field  활용
        name: String::from("Bob"),
        stid: 12345,
        grade: Vec::from([90.0, 85.0, 95.0])
    };

    let student2: Student = Student {
        name: String::from("James"),
        stid:32415,
        grade: Vec::from([50.0, 85.0, 55.0])
    };

    let student3 = Student {
        name: String::from("Kyoungho"),
        stid:32325,
        grade:Vec::from([90.0,75.0,45.0])
    };

    let james_grades = student2.grade  ;                         // student3의 grade 필드를 일단 그대로 가져오기         // james_grades를 바탕으로 평균 구하기 (메소드 사용 안하고 손으로 구하기)


    println!("student3의 이름: {}",student3.name);                 // 구조체 내부의 필드와 method에 잘 접근해서 출력해보기..(Kyungho는 메소드 사용해서 해보기)
    println!("Bob의 학번: {}", student1.stid);
    println!("James의 평균 성적: {}", student2.avg());
    println!("Kyungho의 평균 성적: {}", student3.avg());
}