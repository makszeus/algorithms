fn selection_sort<T: Ord>(arr: &mut [T]) {
    let n = arr.len();
    for i in 0..n - 1 {
        let mut min_index = i;
        for j in i + 1..n {
            if arr[j] < arr[min_index] {
                min_index = j;
            }
        }
        if min_index != i {
            arr.swap(i, min_index);
        }
    }
}
