
struct Fruits {
    fruit: String,
    number: i32,
    cost: String,
}

struct ShoppingItem { 
    item: String,
    number: u8,
    price: f64
}

struct Point{
    x: f64,
    y: f64
}
struct Line{
    start: Point,
    end: Point
}


fn main() {
    let fruitss = Fruits{
        fruit: String::from("Apple"),
        number: 5,
        cost: String::from("$1.00")
    };
    let shop = ShoppingItem{
        item: String::from("상의"),
        number: 5,
        price: 1230.00
    };

    let stpt = Point {
        x: 0.0,
        y: 0.0
    };
    let edpt = Point{
        x:10.0,
        y:10.0
    };
    let line = Line{
        start: stpt,
        end: edpt
    }; 

    println!("과일은 {}, 수량은 {}개, 가격은{}",fruitss.fruit,fruitss.number,fruitss.cost);
    println!("상품: {}, 수량: {}, 가격: ${:.2}",shop.item, shop.number, shop.price);
    println!("시작점: ({},{}), 끝점: ({},{})",line.start.x,line.start.y,line.end.x,line.end.y);
}
