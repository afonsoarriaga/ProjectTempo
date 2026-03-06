# How to improve accuracy of benchmarks on Debian 13 (Minimal)

### 1. Isolate Core 3 at Boot

Edit GRUB:
```console
sudo vim /etc/default/grub
```

Find `GRUB_CMDLINE_LINUX_DEFAULT` and add the isolation parameters:
```console
GRUB_CMDLINE_LINUX_DEFAULT="quiet isolcpus=3 nohz_full=3 rcu_nocbs=3"
```

Apply and reboot:
```console
sudo update-grub
sudo reboot
```

After reboot, verify core 3 is isolated:
```console
cat /sys/devices/system/cpu/isolated
# should print: 3
```

What each parameter does:
- isolcpus=3 — excludes core 3 from the kernel scheduler; no other process will be assigned to it
- nohz_full=3 — disables the periodic timer tick on core 3
- rcu_nocbs=3 — offloads RCU callbacks away from core 3, removing another source of interruptions

### 2. Fix CPU frequency

Install required tools:
```console
sudo apt install linux-cpupower
```

Underclock CPU:
```console
# inspect available frequencies and current governor
cpupower frequency-info

# switch to manual control
sudo cpupower frequency-set -g userspace

# pin to minimum frequency (replace 800MHz with your actual minimum from frequency-info)
sudo cpupower frequency-set -f 800MHz

# verify all cores show the same fixed frequency
watch -n 1 "grep MHz /proc/cpuinfo"
```

To restore after benchmarking:
```console
sudo cpupower frequency-set -g performance
```

### 3. Disable hyperthreading

Find hyperthreading sibling core:
```console
cat /sys/devices/system/cpu/cpu3/topology/thread_siblings_list
# will print something like: 1,3
```

Disable it:
```console
echo 0 | sudo tee /sys/devices/system/cpu/cpu1/online
```

### 4. Disable ASLR
Run:
```console
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
```

### 5. Run benchmarks on isolated core 3 with the highest priority
```console
sudo nice -n -20 taskset -c 3 python3 main_count_cycles_x86.py
```