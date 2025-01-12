fn radix_sort(arr: &mut [i32]) {
    if arr.is_empty() {
        return;
    }

    let max_value = *arr.iter().max().unwrap();
    let mut exp = 1;

    while max_value / exp > 0 {
        counting_sort_by_digit(arr, exp);
        exp *= 10;
    }
}

fn counting_sort_by_digit(arr: &mut [i32], exp: i32) {
    let mut counts = vec![0; 10];
    let mut output = vec![0; arr.len()];

    for &num in arr.iter() {
        let digit = (num / exp) % 10;
        counts[digit as usize] += 1;
    }

    for i in 1..10 {
        counts[i] += counts[i - 1];
    }

    for &num in arr.iter().rev() {
        let digit = (num / exp) % 10;
        output[counts[digit as usize] as usize - 1] = num;
        counts[digit as usize] -= 1;
    }

    arr.copy_from_slice(&output);
}

