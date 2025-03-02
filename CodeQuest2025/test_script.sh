#!/bin/bash

TEST_CASES_FILE="test_cases.txt"
OUTPUT_FILE="output.txt"

> "$OUTPUT_FILE"

while IFS= read -r line; do
    expression=$(echo "$line" | cut -d '=' -f 1 | xargs)
    expected_output=$(echo "$line" | cut -d '=' -f 2 | xargs)

    program_output=$(echo "$expression" | ./a.out 2>&1)

    if [[ "$program_output" == "$expected_output" ]]; then
        echo "Test passed: '$expression' -> '$program_output'" >> "$OUTPUT_FILE"
    else
        echo "Test failed: '$expression' -> Expected '$expected_output', Got '$program_output'" >> "$OUTPUT_FILE"
    fi
done < "$TEST_CASES_FILE"

cat "$OUTPUT_FILE"
