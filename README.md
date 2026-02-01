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
      title = {Tempo: {ML}-{KEM} to {PAKE} Compiler Resilient to Timing Attacks},
      howpublished = {Cryptology {ePrint} Archive, Paper 2025/1399},
      year = {2025},
      url = {https://eprint.iacr.org/2025/1399}
}
```

## Benchmarks on 64-bit x86 (x86_64) and ARM (aarch64)

To compile and run the benchmarks:
```
% git clone https://github.com/afonsoarriaga/TempoPAKE.git
% cd TempoPAKE
% git submodule update --init --recursive
% make
% python3 main.py
```

If you have a Mac M1, you can measure CPU cycles (instead of elapsed milliseconds) by running the following command instead (this is based on the work of [@ibireme](https://gist.github.com/ibireme/) and requires root privileges):
```
% sudo python3 main_count_cycles_mac_m1.py
```

Results (on a MacBook Air M1, 2020):

|                  |  Algorithm A0  |   Algorithm A1   |    Algorithm B0   |   Algorithm C0   |   Algorithm C1   |
|------------------|---------------:|-----------------:|------------------:|-----------------:|-----------------:|
| MLKEM-512.gen_a  |  20 796 cycles |   347 000 cycles |  2 493 390 cycles |   541 250 cycles |   171 401 cycles |
| MLKEM-768.gen_a  |  43 371 cycles |   776 666 cycles |  5 605 677 cycles | 1 211 064 cycles |   381 841 cycles |
| MLKEM-1024.gen_a |  77 542 cycles | 1 377 332 cycles |  9 962 866 cycles | 2 150 130 cycles |   676 883 cycles |
|                  |                |                  |                   |                  |                  |
| MLKEM-512        | 249 415 cycles | 1 212 835 cycles |  7 688 806 cycles | 1 792 566 cycles |   684 252 cycles |
| MLKEM-768        | 411 684 cycles | 2 570 535 cycles | 17 077 331 cycles | 3 882 878 cycles | 1 389 138 cycles |
| MLKEM-1024       | 630 139 cycles | 4 474 207 cycles | 30 229 976 cycles | 6 801 575 cycles | 2 368 664 cycles |
|                  |                |                  |                   |                  |                  |
| NoIC[MLKEM-512]  | 340 725 cycles | 1 621 402 cycles | 10 228 453 cycles | 2 401 830 cycles |   923 869 cycles |
| NoIC[MLKEM-768]  | 546 484 cycles | 3 184 602 cycles | 20 993 196 cycles | 4 787 709 cycles | 1 740 766 cycles |
| NoIC[MLKEM-1024] | 807 616 cycles | 5 301 191 cycles | 35 400 992 cycles | 8 005 898 cycles | 2 837 613 cycles |

Average cycle count: ML-KEM runs keygen+enc+dec; NoIC runs init+resp+end.

- Algorithm A0 : VT rejection sampling, following [FIPS 203, Algorithm 7](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.203.pdf) blueprint
- Algorithm A1 : CT rejection sampling, functionally equivalent to [FIPS 203, Algorithm 7](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.203.pdf)
- Algorithm B0 : CT recursive division with remainder over 3200-bit integer (OpenSSL required)
- Algorithm C0 : CT modular reduction over 192-bit integers (OpenSSL required)
- Algorithm C1 : CT modular reduction over 192-bit integers (standalone)

## Benchmarks on ARM Cortex-M4

These instructions are for a Nucleo-L4R5ZI board connected to a laptop running MacOS 15.6.1.

1. Download and install manually arm-gnu-toolchain-13.3.rel1-darwin-arm64-arm-none-eabi.pkg. Brew installs version 14.3.rel1 which doesn't work as of 26/09/2025.
```
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
```
% brew install openocd
```
3. Copy PAKEs to pqm4
```
% make copy-pakes
```
4. Compile 
```
% cd external/pqm4
% make -j4 PLATFORM=nucleo-l4r5zi
```
5. Install Python dependences
```
% python3 -m venv venv
% source venv/bin/activate
% pip3 install -r requirements.txt
```
6. Connect board
```
% ls /dev/tty.*
/dev/tty.usbmodem1103
```
7. Run benchmarks with 100 iterations
```
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
