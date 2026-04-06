# Speed Evaluation
## Key Encapsulation Schemes
| scheme | implementation | key generation [cycles] | encapsulation [cycles] | decapsulation [cycles] |
| ------ | -------------- | ----------------------- | ---------------------- | ---------------------- |
| ml-kem-1024 (100 executions) | clean | AVG: 1,536,966 <br /> MIN: 1,535,124 <br /> MAX: 1,547,637 | AVG: 1,708,715 <br /> MIN: 1,706,906 <br /> MAX: 1,719,402 | AVG: 2,020,960 <br /> MIN: 2,019,108 <br /> MAX: 2,031,644 |
| ml-kem-1024 (100 executions) | m4fspeed | AVG: 1,017,022 <br /> MIN: 1,014,421 <br /> MAX: 1,027,630 | AVG: 1,029,633 <br /> MIN: 1,027,046 <br /> MAX: 1,040,281 | AVG: 1,092,067 <br /> MIN: 1,089,479 <br /> MAX: 1,102,714 |
| ml-kem-1024 (100 executions) | m4fstack | AVG: 1,020,242 <br /> MIN: 1,016,796 <br /> MAX: 1,040,773 | AVG: 1,037,999 <br /> MIN: 1,034,552 <br /> MAX: 1,058,526 | AVG: 1,101,030 <br /> MIN: 1,097,583 <br /> MAX: 1,121,557 |
| ml-kem-512 (100 executions) | clean | AVG: 596,338 <br /> MIN: 595,557 <br /> MAX: 607,220 | AVG: 701,145 <br /> MIN: 700,365 <br /> MAX: 712,029 | AVG: 889,194 <br /> MIN: 888,414 <br /> MAX: 900,078 |
| ml-kem-512 (100 executions) | m4fspeed | AVG: 393,163 <br /> MIN: 392,146 <br /> MAX: 403,970 | AVG: 391,617 <br /> MIN: 390,600 <br /> MAX: 402,425 | AVG: 428,902 <br /> MIN: 427,884 <br /> MAX: 439,709 |
| ml-kem-512 (100 executions) | m4fstack | AVG: 392,904 <br /> MIN: 391,583 <br /> MAX: 403,589 | AVG: 393,541 <br /> MIN: 392,220 <br /> MAX: 404,230 | AVG: 430,876 <br /> MIN: 429,556 <br /> MAX: 441,566 |
| ml-kem-768 (100 executions) | clean | AVG: 987,580 <br /> MIN: 986,011 <br /> MAX: 997,930 | AVG: 1,137,080 <br /> MIN: 1,135,511 <br /> MAX: 1,147,429 | AVG: 1,386,841 <br /> MIN: 1,385,272 <br /> MAX: 1,397,212 |
| ml-kem-768 (100 executions) | m4fspeed | AVG: 641,152 <br /> MIN: 638,906 <br /> MAX: 651,746 | AVG: 657,809 <br /> MIN: 655,563 <br /> MAX: 668,403 | AVG: 706,875 <br /> MIN: 704,631 <br /> MAX: 717,471 |
| ml-kem-768 (100 executions) | m4fstack | AVG: 641,615 <br /> MIN: 640,374 <br /> MAX: 652,965 | AVG: 662,076 <br /> MIN: 660,839 <br /> MAX: 673,430 | AVG: 711,613 <br /> MIN: 710,376 <br /> MAX: 722,967 |
| noic-a0-mlkem1024 (100 executions) | ref | AVG: 2,504,947 <br /> MIN: 2,493,157 <br /> MAX: 2,528,913 | AVG: 3,308,690 <br /> MIN: 3,296,897 <br /> MAX: 3,332,653 | AVG: 3,143,844 <br /> MIN: 3,131,497 <br /> MAX: 3,165,306 |
| noic-a0-mlkem512 (100 executions) | ref | AVG: 951,455 <br /> MIN: 946,231 <br /> MAX: 965,040 | AVG: 1,410,510 <br /> MIN: 1,405,287 <br /> MAX: 1,424,095 | AVG: 1,348,622 <br /> MIN: 1,344,567 <br /> MAX: 1,362,150 |
| noic-a0-mlkem768 (100 executions) | ref | AVG: 1,645,490 <br /> MIN: 1,636,736 <br /> MAX: 1,660,353 | AVG: 2,271,898 <br /> MIN: 2,263,141 <br /> MAX: 2,286,759 | AVG: 2,164,005 <br /> MIN: 2,156,402 <br /> MAX: 2,174,099 |
| noic-a1-mlkem1024 (100 executions) | ref | AVG: 72,215,746 <br /> MIN: 72,215,729 <br /> MAX: 72,215,776 | AVG: 73,019,487 <br /> MIN: 73,019,466 <br /> MAX: 73,019,520 | AVG: 58,912,525 <br /> MIN: 58,912,498 <br /> MAX: 58,912,552 |
| noic-a1-mlkem512 (100 executions) | ref | AVG: 21,864,461 <br /> MIN: 21,864,447 <br /> MAX: 21,864,495 | AVG: 22,323,521 <br /> MIN: 22,323,507 <br /> MAX: 22,323,551 | AVG: 15,290,858 <br /> MIN: 15,290,825 <br /> MAX: 15,290,868 |
| noic-a1-mlkem768 (100 executions) | ref | AVG: 43,473,334 <br /> MIN: 43,473,307 <br /> MAX: 43,473,358 | AVG: 44,099,761 <br /> MIN: 44,099,733 <br /> MAX: 44,099,781 | AVG: 33,534,883 <br /> MIN: 33,534,879 <br /> MAX: 33,534,888 |
| noic-c1-mlkem1024 (100 executions) | ref | AVG: 10,159,019 <br /> MIN: 10,158,996 <br /> MAX: 10,159,037 | AVG: 10,962,759 <br /> MIN: 10,962,734 <br /> MAX: 10,962,776 | AVG: 9,267,135 <br /> MIN: 9,267,114 <br /> MAX: 9,267,157 |
| noic-c1-mlkem512 (100 executions) | ref | AVG: 3,247,443 <br /> MIN: 3,247,434 <br /> MAX: 3,247,478 | AVG: 3,706,499 <br /> MIN: 3,706,491 <br /> MAX: 3,706,533 | AVG: 2,879,508 <br /> MIN: 2,879,502 <br /> MAX: 2,879,547 |
| noic-c1-mlkem768 (100 executions) | ref | AVG: 6,239,288 <br /> MIN: 6,239,272 <br /> MAX: 6,239,319 | AVG: 6,865,687 <br /> MIN: 6,865,671 <br /> MAX: 6,865,715 | AVG: 5,609,324 <br /> MIN: 5,609,311 <br /> MAX: 5,609,356 |
| tempo-a1-mlkem1024 (100 executions) | ref | AVG: 16,023,652 <br /> MIN: 16,021,161 <br /> MAX: 16,044,031 | AVG: 16,827,413 <br /> MIN: 16,824,917 <br /> MAX: 16,847,811 | AVG: 2,740,706 <br /> MIN: 2,738,205 <br /> MAX: 2,761,097 |
| tempo-a1-mlkem512 (100 executions) | ref | AVG: 7,811,197 <br /> MIN: 7,810,481 <br /> MAX: 7,821,917 | AVG: 8,270,247 <br /> MIN: 8,269,564 <br /> MAX: 8,280,999 | AVG: 1,247,948 <br /> MIN: 1,247,245 <br /> MAX: 1,258,680 |
| tempo-a1-mlkem768 (100 executions) | ref | AVG: 11,854,589 <br /> MIN: 11,853,585 <br /> MAX: 11,865,647 | AVG: 12,480,987 <br /> MIN: 12,479,983 <br /> MAX: 12,492,000 | AVG: 1,936,396 <br /> MIN: 1,935,378 <br /> MAX: 1,947,433 |
| tempo-c1-mlkem1024 (100 executions) | ref | AVG: 3,612,552 <br /> MIN: 3,609,799 <br /> MAX: 3,632,936 | AVG: 4,416,318 <br /> MIN: 4,413,560 <br /> MAX: 4,436,762 | AVG: 2,740,962 <br /> MIN: 2,738,217 <br /> MAX: 2,761,381 |
| tempo-c1-mlkem512 (100 executions) | ref | AVG: 1,605,497 <br /> MIN: 1,604,737 <br /> MAX: 1,616,429 | AVG: 2,064,549 <br /> MIN: 2,063,788 <br /> MAX: 2,075,439 | AVG: 1,247,926 <br /> MIN: 1,247,166 <br /> MAX: 1,258,817 |
| tempo-c1-mlkem768 (100 executions) | ref | AVG: 2,546,708 <br /> MIN: 2,545,205 <br /> MAX: 2,557,075 | AVG: 3,173,110 <br /> MIN: 3,171,567 <br /> MAX: 3,183,513 | AVG: 1,937,036 <br /> MIN: 1,935,496 <br /> MAX: 1,947,403 |
## Signature Schemes
| scheme | implementation | key generation [cycles] | sign [cycles] | verify [cycles] |
| ------ | -------------- | ----------------------- | ------------- | --------------- |
# Memory Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [bytes] | Encapsulation [bytes] | Decapsulation [bytes] |
| ------ | -------------- | ---------------------- | --------------------- | --------------------- |
## Signature Schemes
| Scheme | Implementation | Key Generation [bytes] | Sign [bytes] | Verify [bytes] |
| ------ | -------------- | ---------------------- | ------------ | -------------- |
# Hashing Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [%] | Encapsulation [%] | Decapsulation [%] |
| ------ | -------------- | ------------------ | ----------------- | ----------------- |
| ml-kem-1024 | clean | 50.0% | 45.6% | 38.6% |
| ml-kem-1024 | m4fspeed | 75.3% | 75.5% | 71.2% |
| ml-kem-1024 | m4fstack | 75.1% | 74.9% | 70.7% |
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
