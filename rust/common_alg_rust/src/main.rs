use rand::Rng;
use std::io;
use std::io::Write;

struct CommonAlg {
    array: [i32; CommonAlg::SIZE],
}

impl CommonAlg {
    const SIZE: usize = 1000;

    fn new() -> Self {
        let mut rng = rand::thread_rng();
        let mut array = [0; CommonAlg::SIZE];
        for i in 0..CommonAlg::SIZE {
            array[i] = rng.gen_range(0..1000);
        }
        CommonAlg { array }
    }

    fn output_all_values(&self) {
        println!("All values in the array:");
        for &val in self.array.iter() {
            print!("{} ", val);
        }
        println!();
    }

    fn sum_all_values(&self) -> i32 {
        self.array.iter().sum()
    }

    fn output_odd_values(&self) {
        println!("Odd values in the array:");
        for &val in self.array.iter() {
            if val % 2 != 0 {
                print!("{} ", val);
            }
        }
        println!();
    }

    fn output_even_values(&self) {
        println!("Even values in the array:");
        for &val in self.array.iter() {
            if val % 2 == 0 {
                print!("{} ", val);
            }
        }
        println!();
    }

    fn linear_search(&self) {
        let mut input = String::new();
        print!("Enter target: ");
        io::stdout().flush().unwrap();
        io::stdin().read_line(&mut input).unwrap();
        let target: i32 = input.trim().parse().unwrap();

        match self.array.iter().position(|&x| x == target) {
            Some(index) => println!("Target: {} found at index: {}", target, index),
            None => println!("Target not found"),
        }
    }

    fn middle_values(&self) {
        let middle_index1 = CommonAlg::SIZE / 2 - 1;
        let middle_index2 = CommonAlg::SIZE / 2;
        let middle_value = (self.array[middle_index1] + self.array[middle_index2]) / 2;
        println!("Middle value: {}", middle_value);
    }

    fn first_value(&self) {
        println!("First value: {} Index: 0", self.array[0]);
    }

    fn last_value(&self) {
        println!("Last value: {} Index: {}", self.array[CommonAlg::SIZE - 1], CommonAlg::SIZE - 1);
    }

    fn highest_value(&self) {
        let (max_val, max_index) = self.array.iter().enumerate().max_by_key(|&(_, &val)| val).unwrap();
        println!("Highest Value: {} Index: {}", max_val, max_index);
    }

    fn lowest_value(&self) {
        let (min_val, min_index) = self.array.iter().enumerate().min_by_key(|&(_, &val)| val).unwrap();
        println!("Lowest Value: {} Index: {}", min_val, min_index);
    }

    fn bubble_sort(&mut self) {
        for i in 0..CommonAlg::SIZE - 1 {
            for j in 0..CommonAlg::SIZE - i - 1 {
                if self.array[j] > self.array[j + 1] {
                    self.array.swap(j, j + 1);
                }
            }
        }
        self.output_all_values();
    }

    fn mean_average(&self) {
        let sum = self.sum_all_values();
        let mean_avg = sum / CommonAlg::SIZE as i32;
        println!("Mean Average: {}", mean_avg);
    }
}

fn main() {
    let mut menu = CommonAlg::new();
    let mut choice = String::new();

    loop {
        println!("\nMenu:");
        println!("A. Output all values");
        println!("B. Sum all values");
        println!("C. Output odd numbers");
        println!("D. Output even numbers");
        println!("E. Linear Search");
        println!("F. Middle Values");
        println!("G. First Value");
        println!("H. Last Value");
        println!("I. Highest Value");
        println!("J. Lowest Value");
        println!("K. Bubble Sort");
        println!("L. Mean Average");
        println!("M. Exit");

        io::stdin()
            .read_line(&mut choice)
            .expect("Failed to read line");

        // Trimming and converting to uppercase
        choice = choice.trim().to_uppercase();

        match choice.as_str() {
            "A" => menu.output_all_values(),
            "B" => println!("Sum: {}", menu.sum_all_values()),
            "C" => menu.output_odd_values(),
            "D" => menu.output_even_values(),
            "E" => menu.linear_search(),
            "F" => menu.middle_values(),
            "G" => menu.first_value(),
            "H" => menu.last_value(),
            "I" => menu.highest_value(),
            "J" => menu.lowest_value(),
            "K" => menu.bubble_sort(),
            "L" => menu.mean_average(),
            "M" => {
                println!("Exiting program.");
                break;
            }
            _ => println!("Invalid choice, please try again."),
        }
        choice.clear();
    }
}
