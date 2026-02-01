# Speed Evaluation
## Key Encapsulation Schemes
| scheme | implementation | key generation [cycles] | encapsulation [cycles] | decapsulation [cycles] |
| ------ | -------------- | ----------------------- | ---------------------- | ---------------------- |
| ml-kem-1024 (100 executions) | clean | AVG: 1,537,040 <br /> MIN: 1,535,439 <br /> MAX: 1,547,934 | AVG: 1,708,789 <br /> MIN: 1,707,186 <br /> MAX: 1,719,708 | AVG: 2,021,034 <br /> MIN: 2,019,428 <br /> MAX: 2,031,950 |
| ml-kem-1024 (100 executions) | m4fspeed | AVG: 1,017,421 <br /> MIN: 1,014,698 <br /> MAX: 1,038,274 | AVG: 1,030,032 <br /> MIN: 1,027,305 <br /> MAX: 1,050,869 | AVG: 1,092,465 <br /> MIN: 1,089,738 <br /> MAX: 1,113,302 |
| ml-kem-1024 (100 executions) | m4fstack | AVG: 1,018,925 <br /> MIN: 1,017,226 <br /> MAX: 1,029,925 | AVG: 1,036,682 <br /> MIN: 1,034,988 <br /> MAX: 1,047,680 | AVG: 1,099,713 <br /> MIN: 1,098,019 <br /> MAX: 1,110,711 |
| ml-kem-512 (100 executions) | clean | AVG: 595,884 <br /> MIN: 595,467 <br /> MAX: 596,320 | AVG: 700,692 <br /> MIN: 700,275 <br /> MAX: 701,128 | AVG: 888,742 <br /> MIN: 888,324 <br /> MAX: 889,177 |
| ml-kem-512 (100 executions) | m4fspeed | AVG: 393,622 <br /> MIN: 391,959 <br /> MAX: 415,133 | AVG: 392,075 <br /> MIN: 390,415 <br /> MAX: 413,588 | AVG: 429,360 <br /> MIN: 427,699 <br /> MAX: 450,872 |
| ml-kem-512 (100 executions) | m4fstack | AVG: 392,661 <br /> MIN: 391,855 <br /> MAX: 414,833 | AVG: 393,298 <br /> MIN: 392,492 <br /> MAX: 415,473 | AVG: 430,634 <br /> MIN: 429,828 <br /> MAX: 452,809 |
| ml-kem-768 (100 executions) | clean | AVG: 986,789 <br /> MIN: 986,043 <br /> MAX: 997,727 | AVG: 1,136,289 <br /> MIN: 1,135,544 <br /> MAX: 1,147,225 | AVG: 1,386,050 <br /> MIN: 1,385,305 <br /> MAX: 1,396,986 |
| ml-kem-768 (100 executions) | m4fspeed | AVG: 640,849 <br /> MIN: 638,858 <br /> MAX: 651,470 | AVG: 657,508 <br /> MIN: 655,551 <br /> MAX: 668,151 | AVG: 706,573 <br /> MIN: 704,619 <br /> MAX: 717,219 |
| ml-kem-768 (100 executions) | m4fstack | AVG: 641,843 <br /> MIN: 640,280 <br /> MAX: 652,468 | AVG: 662,304 <br /> MIN: 660,745 <br /> MAX: 672,932 | AVG: 711,841 <br /> MIN: 710,282 <br /> MAX: 722,469 |
| noic-a0-mlkem1024 (100 executions) | ref | AVG: 2,504,627 <br /> MIN: 2,493,900 <br /> MAX: 2,531,914 | AVG: 3,308,370 <br /> MIN: 3,297,640 <br /> MAX: 3,335,654 | AVG: 3,143,464 <br /> MIN: 3,133,042 <br /> MAX: 3,171,559 |
| noic-a0-mlkem512 (100 executions) | ref | AVG: 950,613 <br /> MIN: 946,457 <br /> MAX: 964,222 | AVG: 1,409,669 <br /> MIN: 1,405,518 <br /> MAX: 1,423,277 | AVG: 1,348,173 <br /> MIN: 1,343,428 <br /> MAX: 1,351,854 |
| noic-a0-mlkem768 (100 executions) | ref | AVG: 1,647,255 <br /> MIN: 1,638,162 <br /> MAX: 1,671,286 | AVG: 2,273,662 <br /> MIN: 2,264,568 <br /> MAX: 2,297,730 | AVG: 2,165,084 <br /> MIN: 2,158,717 <br /> MAX: 2,177,688 |
| noic-a1-mlkem1024 (100 executions) | ref | AVG: 72,215,746 <br /> MIN: 72,215,729 <br /> MAX: 72,215,776 | AVG: 73,019,487 <br /> MIN: 73,019,466 <br /> MAX: 73,019,520 | AVG: 58,912,525 <br /> MIN: 58,912,498 <br /> MAX: 58,912,552 |
| noic-a1-mlkem512 (100 executions) | ref | AVG: 21,864,461 <br /> MIN: 21,864,447 <br /> MAX: 21,864,495 | AVG: 22,323,521 <br /> MIN: 22,323,507 <br /> MAX: 22,323,551 | AVG: 15,290,858 <br /> MIN: 15,290,825 <br /> MAX: 15,290,868 |
| noic-a1-mlkem768 (100 executions) | ref | AVG: 43,473,334 <br /> MIN: 43,473,307 <br /> MAX: 43,473,358 | AVG: 44,099,761 <br /> MIN: 44,099,733 <br /> MAX: 44,099,781 | AVG: 33,534,883 <br /> MIN: 33,534,879 <br /> MAX: 33,534,888 |
| noic-c1-mlkem1024 (100 executions) | ref | AVG: 10,159,019 <br /> MIN: 10,158,996 <br /> MAX: 10,159,037 | AVG: 10,962,759 <br /> MIN: 10,962,734 <br /> MAX: 10,962,776 | AVG: 9,267,135 <br /> MIN: 9,267,114 <br /> MAX: 9,267,157 |
| noic-c1-mlkem512 (100 executions) | ref | AVG: 3,247,443 <br /> MIN: 3,247,434 <br /> MAX: 3,247,478 | AVG: 3,706,499 <br /> MIN: 3,706,491 <br /> MAX: 3,706,533 | AVG: 2,879,508 <br /> MIN: 2,879,502 <br /> MAX: 2,879,547 |
| noic-c1-mlkem768 (100 executions) | ref | AVG: 6,239,288 <br /> MIN: 6,239,272 <br /> MAX: 6,239,319 | AVG: 6,865,687 <br /> MIN: 6,865,671 <br /> MAX: 6,865,715 | AVG: 5,609,324 <br /> MIN: 5,609,311 <br /> MAX: 5,609,356 |
| tempo-a1-mlkem1024 (100 executions) | ref | AVG: 16,023,853 <br /> MIN: 16,020,999 <br /> MAX: 16,044,386 | AVG: 16,827,614 <br /> MIN: 16,824,754 <br /> MAX: 16,848,163 | AVG: 2,740,907 <br /> MIN: 2,738,040 <br /> MAX: 2,761,451 |
| tempo-a1-mlkem512 (100 executions) | ref | AVG: 7,811,188 <br /> MIN: 7,810,286 <br /> MAX: 7,822,092 | AVG: 8,270,238 <br /> MIN: 8,269,372 <br /> MAX: 8,281,181 | AVG: 1,247,940 <br /> MIN: 1,247,051 <br /> MAX: 1,258,860 |
| tempo-a1-mlkem768 (100 executions) | ref | AVG: 11,854,916 <br /> MIN: 11,853,703 <br /> MAX: 11,865,715 | AVG: 12,481,314 <br /> MIN: 12,480,064 <br /> MAX: 12,492,112 | AVG: 1,936,723 <br /> MIN: 1,935,536 <br /> MAX: 1,947,507 |
| tempo-c1-mlkem1024 (100 executions) | ref | AVG: 3,612,339 <br /> MIN: 3,609,700 <br /> MAX: 3,622,261 | AVG: 4,416,104 <br /> MIN: 4,413,502 <br /> MAX: 4,426,036 | AVG: 2,740,748 <br /> MIN: 2,738,122 <br /> MAX: 2,750,693 |
| tempo-c1-mlkem512 (100 executions) | ref | AVG: 1,605,650 <br /> MIN: 1,604,859 <br /> MAX: 1,616,499 | AVG: 2,064,702 <br /> MIN: 2,063,910 <br /> MAX: 2,075,547 | AVG: 1,248,079 <br /> MIN: 1,247,288 <br /> MAX: 1,258,925 |
| tempo-c1-mlkem768 (100 executions) | ref | AVG: 2,546,519 <br /> MIN: 2,545,160 <br /> MAX: 2,556,923 | AVG: 3,172,920 <br /> MIN: 3,171,560 <br /> MAX: 3,183,286 | AVG: 1,936,846 <br /> MIN: 1,935,489 <br /> MAX: 1,947,215 |
## Signature Schemes
| scheme | implementation | key generation [cycles] | sign [cycles] | verify [cycles] |
| ------ | -------------- | ----------------------- | ------------- | --------------- |
# Memory Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [bytes] | Encapsulation [bytes] | Decapsulation [bytes] |
| ------ | -------------- | ---------------------- | --------------------- | --------------------- |
| ml-kem-1024 | clean | 15,128 | 18,776 | 20,352 |
| ml-kem-1024 | m4fspeed | 6,436 | 7,500 | 7,484 |
| ml-kem-1024 | m4fstack | 3,332 | 3,372 | 3,356 |
| ml-kem-512 | clean | 6,152 | 8,784 | 9,560 |
| ml-kem-512 | m4fspeed | 4,372 | 5,436 | 5,412 |
| ml-kem-512 | m4fstack | 2,300 | 2,348 | 2,332 |
| ml-kem-768 | clean | 10,248 | 13,384 | 14,480 |
| ml-kem-768 | m4fspeed | 5,396 | 6,468 | 6,452 |
| ml-kem-768 | m4fstack | 2,820 | 2,860 | 2,844 |
| noic-a0-mlkem1024 | ref | 21,544 | 26,528 | 31,248 |
| noic-a0-mlkem512 | ref | 9,224 | 12,672 | 15,088 |
| noic-a0-mlkem768 | ref | 14,872 | 19,088 | 22,656 |
| noic-a1-mlkem1024 | ref | 21,544 | 26,528 | 31,248 |
| noic-a1-mlkem512 | ref | 9,224 | 12,672 | 15,116 |
| noic-a1-mlkem768 | ref | 14,872 | 19,088 | 22,656 |
| noic-c1-mlkem1024 | ref | 21,544 | 26,612 | 31,248 |
| noic-c1-mlkem512 | ref | 9,224 | 12,672 | 15,088 |
| noic-c1-mlkem768 | ref | 14,872 | 19,088 | 22,656 |
| tempo-a1-mlkem1024 | ref | 21,552 | 26,536 | 31,256 |
| tempo-a1-mlkem512 | ref | 9,504 | 12,960 | 15,376 |
| tempo-a1-mlkem768 | ref | 15,136 | 19,352 | 22,996 |
| tempo-c1-mlkem1024 | ref | 21,552 | 26,536 | 31,256 |
| tempo-c1-mlkem512 | ref | 9,504 | 12,960 | 15,376 |
| tempo-c1-mlkem768 | ref | 15,136 | 19,352 | 22,920 |
## Signature Schemes
| Scheme | Implementation | Key Generation [bytes] | Sign [bytes] | Verify [bytes] |
| ------ | -------------- | ---------------------- | ------------ | -------------- |
# Hashing Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [%] | Encapsulation [%] | Decapsulation [%] |
| ------ | -------------- | ------------------ | ----------------- | ----------------- |
| ml-kem-1024 | clean | 50.0% | 45.7% | 38.6% |
| ml-kem-1024 | m4fspeed | 75.3% | 75.5% | 71.2% |
| ml-kem-1024 | m4fstack | 75.1% | 75.0% | 70.7% |
| ml-kem-512 | clean | 49.9% | 41.2% | 32.5% |
| ml-kem-512 | m4fspeed | 75.5% | 73.5% | 67.2% |
| ml-kem-512 | m4fstack | 75.6% | 73.2% | 66.9% |
| ml-kem-768 | clean | 48.5% | 43.2% | 35.4% |
| ml-kem-768 | m4fspeed | 74.5% | 74.4% | 69.2% |
| ml-kem-768 | m4fstack | 74.4% | 73.9% | 68.7% |
| noic-a0-mlkem1024 | ref | 60.0% | 64.5% | 56.7% |
| noic-a0-mlkem512 | ref | 59.8% | 64.5% | 53.4% |
| noic-a0-mlkem768 | ref | 59.8% | 64.5% | 55.4% |
| noic-a1-mlkem1024 | ref | 3.6% | 4.4% | 4.5% |
| noic-a1-mlkem512 | ref | 4.1% | 5.5% | 6.1% |
| noic-a1-mlkem768 | ref | 3.7% | 4.8% | 5.0% |
| noic-c1-mlkem1024 | ref | 84.6% | 84.3% | 80.6% |
| noic-c1-mlkem512 | ref | 83.1% | 82.2% | 74.5% |
| noic-c1-mlkem768 | ref | 84.0% | 83.5% | 78.4% |
| tempo-a1-mlkem1024 | ref | 8.8% | 12.2% | 54.3% |
| tempo-a1-mlkem512 | ref | 7.6% | 11.3% | 51.6% |
| tempo-a1-mlkem768 | ref | 8.1% | 11.6% | 53.3% |
| tempo-c1-mlkem1024 | ref | 72.8% | 74.2% | 54.3% |
| tempo-c1-mlkem512 | ref | 74.8% | 75.0% | 51.6% |
| tempo-c1-mlkem768 | ref | 73.7% | 74.6% | 53.3% |
## Signature Schemes
| Scheme | Implementation | Key Generation [%] | Sign [%] | Verify [%] |
| ------ | -------------- | ------------------ | -------- | ---------- |
# Size Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |
| ml-kem-1024 | clean | 6,160 | 0 | 0 | 6,160 |
| ml-kem-1024 | m4fspeed | 16,916 | 0 | 0 | 16,916 |
| ml-kem-1024 | m4fstack | 14,016 | 0 | 0 | 14,016 |
| ml-kem-512 | clean | 5,116 | 0 | 0 | 5,116 |
| ml-kem-512 | m4fspeed | 15,848 | 0 | 0 | 15,848 |
| ml-kem-512 | m4fstack | 13,328 | 0 | 0 | 13,328 |
| ml-kem-768 | clean | 5,120 | 0 | 0 | 5,120 |
| ml-kem-768 | m4fspeed | 16,016 | 0 | 0 | 16,016 |
| ml-kem-768 | m4fstack | 13,320 | 0 | 0 | 13,320 |
| noic-a0-mlkem1024 | ref | 6,996 | 0 | 0 | 6,996 |
| noic-a0-mlkem512 | ref | 6,968 | 0 | 0 | 6,968 |
| noic-a0-mlkem768 | ref | 7,032 | 0 | 0 | 7,032 |
| noic-a1-mlkem1024 | ref | 7,132 | 0 | 0 | 7,132 |
| noic-a1-mlkem512 | ref | 7,104 | 0 | 0 | 7,104 |
| noic-a1-mlkem768 | ref | 7,168 | 0 | 0 | 7,168 |
| noic-c1-mlkem1024 | ref | 7,494 | 0 | 0 | 7,494 |
| noic-c1-mlkem512 | ref | 7,466 | 0 | 0 | 7,466 |
| noic-c1-mlkem768 | ref | 7,530 | 0 | 0 | 7,530 |
| tempo-a1-mlkem1024 | ref | 7,744 | 0 | 0 | 7,744 |
| tempo-a1-mlkem512 | ref | 7,016 | 0 | 0 | 7,016 |
| tempo-a1-mlkem768 | ref | 7,148 | 0 | 0 | 7,148 |
| tempo-c1-mlkem1024 | ref | 8,106 | 0 | 0 | 8,106 |
| tempo-c1-mlkem512 | ref | 7,378 | 0 | 0 | 7,378 |
| tempo-c1-mlkem768 | ref | 7,510 | 0 | 0 | 7,510 |
## Signature Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |