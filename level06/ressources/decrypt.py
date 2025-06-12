def custom_hash(input_str):
    if len(input_str) < 4:
        raise ValueError("Input string must be at least 4 characters long.")
    
    # Initialize local_14 based on the 4th character (index 3)
    local_14 = (ord(input_str[3]) ^ 0x1337) + 0x5eeded

    for c in input_str:
        if ord(c) < 0x20:  # Control characters (non-printable)
            return -1  # Mimics return 1 from the C code
        local_14 += (ord(c) ^ local_14) % 0x539

    return local_14

# Example usage:
if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python3 hash_calc.py <input_string>")
        sys.exit(1)

    s = sys.argv[1]
    result = custom_hash(s)
    if result == -1:
        print("Invalid input: contains control characters.")
    else:
        print(f"Hash result: {result}")
