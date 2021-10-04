mod simple_sort;
#[cfg(test)]
mod tests {
    use crate::simple_sort;
    #[test]
    fn bubble_works () {
        let mut arr = vec![8, 1, 5, 3, 6, 9, 12, 23, 42, 41];
        println!("{:?}", arr);
        simple_sort::bubble_sort(&mut arr);
        println!("{:?}", arr);
    }

    #[test]
    fn select_works () {
        let mut arr = vec![8, 1, 5, 3, 6, 9, 12, 23, 42, 41];
        println!("{:?}", arr);
        simple_sort::select_sort(&mut arr);
        println!("{:?}", arr);
    }

    #[test]
    fn insert_works () {
        let mut arr = vec![8, 1, 5, 3, 6, 9, 12, 23, 42, 41];
        println!("{:?}", arr);
        simple_sort::insert_sort(&mut arr);
        println!("{:?}", arr);
    }
}
