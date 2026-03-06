# Project Tempo

> [!NOTE]
> This project is an artifact of [Tempo PAKE](https://eprint.iacr.org/2025/1399).
> It benchmarks alternative specifications/implementations of the ML-KEM SampleNTT algorithm specified in [FIPS 203, Algorithm 7](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.203.pdf).
> This project has two Git submodules: `OpenSSL` and `pqm4`.
> Algorithms A0, A1 and C1 are self-contained. Algorithms B0 and C0 require OpenSSL.
> Running the main python script produces the benchmarks presented in Table 1 of the paper.
> To run the benchmarks on ARM Cortex-M4, see instructions below. Results are provided in `pqm4_results.md` and summarized in Table 2 of the paper.

## Bibliography

When referring to Tempo PAKE or this GitHub repository in academic literature, please consider citing this work:
```
@misc{cryptoeprint:2025/1399,
      author = {Afonso Arriaga and Manuel Barbosa and Stanislaw Jarecki},
      title = {Tempo: An {ML}-{KEM} to {PAKE} Compiler Resilient to Timing Attacks},
      howpublished = {Cryptology {ePrint} Archive, Paper 2025/1399},
      year = {2025},
      url = {https://eprint.iacr.org/2025/1399}
}
```

## Benchmarks on 64-bit x86 (x86_64) and ARM (aarch64)

To compile and run the benchmarks:
```console
% git clone https://github.com/afonsoarriaga/ProjectTempo.git
% cd ProjectTempo
% git submodule update --init --recursive
% make
% python3 main.py
```

If you have a Mac M1, you can measure CPU cycles (instead of elapsed milliseconds) by running the following command instead (this is based on the work of [@ibireme](https://gist.github.com/ibireme/) and requires root privileges):
```console
% sudo python3 main_count_cycles_mac_m1.py
```

If you have a Linux OS running on x86, use the following command:
```console
% python3 main_count_cycles_x86.py
```

Results (on a MacBook Air M1, 2020):

|                  |  Algorithm A0  |   Algorithm A1   |    Algorithm B0   |   Algorithm C0   |   Algorithm C1   |
|------------------|---------------:|-----------------:|------------------:|-----------------:|-----------------:|
| MLKEM-512.gen_a  |      0.0077 ms |        0.4504 ms |         0.7837 ms |        0.1710 ms |        0.0609 ms |
| MLKEM-768.gen_a  |      0.0146 ms |        1.0075 ms |         1.7718 ms |        0.4481 ms |        0.1342 ms |
| MLKEM-1024.gen_a |      0.0261 ms |        1.7997 ms |         3.1335 ms |        0.6843 ms |        0.2382 ms |
|                  |                |                  |                   |                  |                  |
| MLKEM-512        |      0.0902 ms |        1.4328 ms |         2.4261 ms |        0.5813 ms |        0.2454 ms |
| MLKEM-768        |      0.1485 ms |        3.1401 ms |         5.4544 ms |        1.2506 ms |        0.5001 ms |
| MLKEM-1024       |      0.2266 ms |        5.5491 ms |         9.7576 ms |        2.1966 ms |        0.8483 ms |
|                  |                |                  |                   |                  |                  |
| NoIC[MLKEM-512]  |      0.1248 ms |        1.9081 ms |         3.2615 ms |        0.7846 ms |        0.3319 ms |
| NoIC[MLKEM-768]  |      0.1965 ms |        3.8854 ms |         6.6772 ms |        1.6083 ms |        0.6232 ms |
| NoIC[MLKEM-1024] |      0.2871 ms |        6.6271 ms |        11.2986 ms |        2.5864 ms |        1.0233 ms |

Average cycle count: ML-KEM runs keygen+enc+dec; NoIC runs init+resp+end.

- Algorithm A0 : VT rejection sampling, following [FIPS 203, Algorithm 7](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.203.pdf) blueprint
- Algorithm A1 : CT rejection sampling, functionally equivalent to [FIPS 203, Algorithm 7](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.203.pdf)
- Algorithm B0 : CT recursive division with remainder over 3200-bit integer (OpenSSL required)
- Algorithm C0 : CT modular reduction over 192-bit integers (OpenSSL required)
- Algorithm C1 : CT modular reduction over 192-bit integers (standalone)

## Benchmarks on ARM Cortex-M4

These instructions are for a Nucleo-L4R5ZI board connected to a laptop running MacOS 15.6.1.

1. Download and install manually arm-gnu-toolchain-13.3.rel1-darwin-arm64-arm-none-eabi.pkg. Brew installs version 14.3.rel1 which doesn't work as of 26/09/2025.
```console
% vim ~/.zshrc
export PATH="/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin:$PATH"

% source ~/.zshrc

% which arm-none-eabi-gcc && arm-none-eabi-gcc --version
/Applications/ArmGNUToolchain/13.3.rel1/arm-none-eabi/bin/arm-none-eabi-gcc
arm-none-eabi-gcc (Arm GNU Toolchain 13.3.Rel1 (Build arm-13.24)) 13.3.1 20240614
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
2. Install OpenOCD to allow benchmarks.py to flash the compiled binaries
```console
% brew install openocd
```
3. Copy PAKEs to pqm4
```console
% make copy-pakes
```
4. Compile 
```console
% cd external/pqm4
% make -j4 PLATFORM=nucleo-l4r5zi
```
5. Install Python dependences
```console
% python3 -m venv venv
% source venv/bin/activate
% pip3 install -r requirements.txt
```
6. Connect board
```console
% ls /dev/tty.*
/dev/tty.usbmodem1103
```
7. Run benchmarks with 100 iterations
```console
% python3 benchmarks.py -p nucleo-l4r5zi -u /dev/tty.usbmodem1103 -i 100 \
    ml-kem-512 ml-kem-768 ml-kem-1024 \
    noic-a0-mlkem512 noic-a0-mlkem768 noic-a0-mlkem1024 \
    noic-a1-mlkem512 noic-a1-mlkem768 noic-a1-mlkem1024 \
    noic-c1-mlkem512 noic-c1-mlkem768 noic-c1-mlkem1024 \
    tempo-a1-mlkem512 tempo-a1-mlkem768 tempo-a1-mlkem1024 \
    tempo-c1-mlkem512 tempo-c1-mlkem768 tempo-c1-mlkem1024
% python3 convert_benchmarks.py md
```

For convenience, the results are available in *pqm4_results.md*.

## License

Submodules located in the `external` directory have their own license agreements. We are using public domain code for ML-KEM and SHA-3. All original work in this repository is licensed under [Apache 2.0](https://www.apache.org/licenses/LICENSE-2.0.html).
