
//실습1
enum Shape{
    Circle(f64),
    Rectangle(f64, f64),
    Triangle(f64,f64)
}

fn calculate_area(shape:Shape) -> f64{
    match shape{
        Shape::Circle(radius)=> 3.14 * radius*radius,
        Shape::Rectangle(width, height) => width*height,
        Shape::Triangle(width, hieght) => width*hieght/2.0
    }
}

// 실습2 > struct만들고 impl로 status출력 impl안에서도 &self를 통해 자기 자신의 값 참조
enum OrderStatus{
    Pending,
    Processing,
    Shipped,
    Dilivered
}

struct Order{
    id: u64,
    status: OrderStatus
}

impl Order{
    fn new(id: u64, status: OrderStatus) -> Self{
        Order{ id, status}
    }
    fn display_status(&self){
        let status_message = match self.status{
            OrderStatus::Pending => "Pending, Checking your order",
            OrderStatus::Processing => "Processing",
            OrderStatus::Dilivered => "Delivered",
            OrderStatus::Shipped => "Shipped"
        };
        println!("Order ID: {} - Status: {}", self.id, status_message)

    }
}


//실습3 > structure를 만들고 struct를 참조해 함수선언
enum Position{
    Manager,
    Engineer,
    Intern,
}

struct Employee{
    name:String,
    position: Position,
    years: u32
}

fn calculate_salary(employee: &Employee) -> f32{
    match employee.position{
        Position::Intern => 500000.0 + (2000.0 * employee.years as f32),
        Position::Engineer => 200000.0 + (1000.0 * employee.years as f32),
        Position::Manager => 400000.0 + (1500.0 * employee.years as f32)
    }
}

fn main() {
    let circle = Shape::Circle(3.0);
    let rectangle = Shape::Rectangle(3.0,4.0);
    let triangle = Shape::Triangle(3.0,4.0);

    println!("삼각형 넓이: {}",calculate_area(triangle));
    println!("사각형 넓이: {}", calculate_area(rectangle));
    println!("원 넓이: {:.3}", calculate_area(circle));

    let order1 = Order::new(123456, OrderStatus::Pending);
    let order2 = Order::new(123422, OrderStatus::Processing);
    let order3 = Order::new(123123, OrderStatus::Dilivered);
    let order4 = Order::new(123444, OrderStatus::Shipped);

    order1.display_status();
    order2.display_status();
    order3.display_status();
    order4.display_status();
    
    let manager = Employee{
        name: String::from("윤지상"),
        position: Position::Manager,
        years: 5
    };
    let engineer = Employee{
        name: String::from("김민우"),
        position: Position::Engineer,
        years: 3
    };
    let intern = Employee{
        name: String::from("이호연"),
        position: Position::Intern,
        years: 1
    };

    println!("{}의 급여: ${}", manager.name ,calculate_salary(&manager));
    println!("{}의 급여: ${}", engineer.name , calculate_salary(&engineer));
    println!("{}의 급여: ${}",intern.name , calculate_salary(&intern));
}
