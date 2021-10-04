//< 选择排序
pub fn select_sort<T: Ord>(arr: &mut [T]) {
    let mut min_idx;
    let len = arr.len();

    if len < 2 {
        return;
    }

    for i in 0..len {
        min_idx = i;
        for j in (i + 1)..len {
            if arr[min_idx] > arr[j] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }
}

//< 冒泡排序
pub fn bubble_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    if len < 2 {
        return;
    }

    for i in 0..(len - 1) {
        for j in 1..(len - i) {
            if arr[j - 1] > arr[j] {
                arr.swap(j, j - 1);
            }
        }
    }
}

//< 插入排序
pub fn insert_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();

    if len < 2 {
        return;
    }

    for i in 1..len {
        for j in 1..i {
            if arr[j - 1] > arr[j] {
                arr.swap(j - 1, j);
            }
        }
    }
}
