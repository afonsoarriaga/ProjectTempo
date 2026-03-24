#!/usr/bin/env python3
import sys
import os
import math

def parse_file(path):
    vals = {"keypair": None, "encaps": None, "decaps": None}
    with open(path, "r") as f:
        lines = [l.strip() for l in f if l.strip()]
    for i, line in enumerate(lines):
        if line.startswith("keypair cycles:"):
            vals["keypair"] = int(lines[i+1])
        elif line.startswith("encaps cycles:"):
            vals["encaps"] = int(lines[i+1])
        elif line.startswith("decaps cycles:"):
            vals["decaps"] = int(lines[i+1])
    return vals

def mean_std(xs):
    n = len(xs)
    if n == 0:
        return float("nan"), float("nan")
    m = sum(xs) / n
    var = sum((x - m) ** 2 for x in xs) / (n - 1) if n > 1 else 0.0
    return m, math.sqrt(var)

def main():
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} DIR", file=sys.stderr)
        sys.exit(1)

    dirpath = sys.argv[1]
    keypairs, encaps, decaps = [], [], []

    for name in os.listdir(dirpath):
        path = os.path.join(dirpath, name)
        if not os.path.isfile(path):
            continue
        vals = parse_file(path)
        if vals["keypair"] is not None:
            keypairs.append(vals["keypair"])
        if vals["encaps"] is not None:
            encaps.append(vals["encaps"])
        if vals["decaps"] is not None:
            decaps.append(vals["decaps"])

    for label, data in [("keypair", keypairs),
                        ("encaps", encaps),
                        ("decaps", decaps)]:
        m, s = mean_std(data)
        print(f"{label}: {m:.2f} +- {s:.2f} (n={len(data)})")

if __name__ == "__main__":
    main()
