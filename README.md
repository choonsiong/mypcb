# About

This program generates the __MTD data text file__ required for LHDN PCB submission (for example via online banking portal). 

#### Program Limitation

- Supports only one employer number
- Supports only one employee entry

### Reference

- [MTD Data specification](http://lampiran1.hasil.gov.my/pdf/pdfam/FormatDataCP39BI.pdf)
- [Specification for MTD Calculations Using Computerised Calculation for 2019](http://lampiran1.hasil.gov.my/pdf/pdfam/Spesifikasi_Kaedah_Pengiraan_Berkomputer_PCB_2019.pdf)


### Build steps

Use `make` to build the program with the `Makefile` provided.

Below example specify the user's home directory for `prefix`, `$HOME/etc` where the configuration file can be found and `$HOME/Desktop` to store the output file. Note the default configuration directory is `/etc` and the default output directory is `/tmp`.

```  
$ make prefix=$HOME sysconfdir=$HOME/etc outputdir=$HOME/Desktop all    
cd src && /Applications/Xcode.app/Contents/Developer/usr/bin/make all
gcc -DCFGDIR="\"/Users/choonsiong/etc\"" -DOUTPUTDIR="\"/Users/choonsiong/Desktop\"" -g -O0 -I ../include Helper.c PCBData.c PCBFile.c main.c -o mypcb  
```

Run `make install` to install the program to the directory specified.

```
$ make install
cd src && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
install -d /Users/choonsiong/bin
install -m 0755 mypcb /Users/choonsiong/bin
 
$ ls -l ~/bin
total 112
-rwxr-xr-x  1 choonsiong  staff  54312 Feb 22 03:58 mypcb* 
```

### Usage

```
$ ./mypcb --help
Usage: my_pcb YEAR MONTH PCB_AMOUNT

	YEAR         from 1970 to 2100
	MONTH        from 1 to 12
	PCB_AMOUNT   from 0 (0.00) to 1000000 (10000.00)

	e.g.
	 PCB for 2018 Jan is $1234.56, so enter:
	 my_pcb 2018 01 123456
```

For example, below generate the data file for January 2025 with monthly PCB contribution 1234.56.

```
$ ./mypcb 2025 01 123456
Data file written to /Users/choonsiong/Desktop/PCB_202501.txt
```
