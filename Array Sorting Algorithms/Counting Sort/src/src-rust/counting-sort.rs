fn counting_sort(arr: &mut [usize], max_value: usize) {
    let mut counts = vec![0; max_value + 1];

    for &num in arr.iter() {
        counts[num] += 1;
    }

    let mut index = 0;
    for (num, &count) in counts.iter().enumerate() {
        for _ in 0..count {
            arr[index] = num;
            index += 1;
        }
    }
}
