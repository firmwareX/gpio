# GPIO

build

```bash
sudo apt install --reinstall build-essential
```

```bash
gcc gpio.c -o gpio
```

usage


set pin in
```bash
./gpio set 2 in
```

set pin out
```bash
./gpio set 2 out
```

high

```bash
./gpio write 2 1
```

low

```bash
./gpio write 2 0
```

reading

```bash
./gpio read 2
```
