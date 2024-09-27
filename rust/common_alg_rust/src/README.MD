## BUILD/RUN

### Step 1: Ensure `rand` is added as a dependency
Make sure your `Cargo.toml` file has the correct dependency. Open `Cargo.toml` and ensure it looks like this:

```toml
[dependencies]
rand = "0.8"
```

### Step 2: Run `cargo build` again
After adding the dependency, run:
```bash
cargo build
```
This will fetch the `rand` crate and compile it into your project.

### Step 3: Update `main.rs`
Now, ensure that you are correctly importing the `rand` crate in `main.rs` by adding:

```rust
use rand::Rng;
```

This ensures that Rust knows to use the random number generation functionality from the `rand` crate.

### Step 4: Clean and rebuild (optional)
If the error persists, you can clean the project and try rebuilding it:
```bash
cargo clean
cargo build
```

### Step 5: Run the project
Once the build is successful, run the project:
```bash
cargo run
```

### OUTPUT
```bash
    Menu:
    A. Output all values
    B. Sum all values
    C. Output odd numbers
    D. Output even numbers
    E. Linear Search
    F. Middle Values
    G. First Value
    H. Last Value
    I. Highest Value
    J. Lowest Value
    K. Bubble Sort
    L. Mean Average
    M. Exit
```