﻿
# Grep for windows

a grep coommand for windows like linux grep command. which works on text file to show and search on a text file.





## Demo

a small demo of the project.
![Demo Image](https://github.com/h4jack/grep/blob/main/demo.png?raw=true)


## Installation

Install my-project with git and cmd


#### Clone the grep repo to local machine.
```cmd
git clone https://github.com/h4jack/grep.git grep
```
#### change the path to grep/repo folder.
```cmd  
cd ./grep
```
#### Copy the binary to environment path
```cmd
cp grep.exe C:\Windows\System32\grep.exe 
```
## Running Tests

To run tests, run the following command


```cmd
grep test.txt hello
```
#### Output
```cmd
PS C:\> grep .\test.txt https://
54   : https://www.technipages.com/windows-11-how-to-disable-quick-searcâ€¦
65   : https://answers.microsoft.com/en-us/windows/forum/all/how-can-i â€¦
114  : https://10scopes.com/disable-quick-searches-on-windows-11-10
121  : https://www.tenforums.com/tutorials/1â€¦
137  : https://www.askvg.com/tip-enable-or-diâ€¦
146  : https://www.thewindowsclub.com/how â€¦
154  : https://geekermag.com/how-to-disable-new-bing-search-bar-on-winâ€¦
161  : https://learn.microsoft.com/en-us/microsoftsearch/edge-shortcuts
167  : https://learn.microsoft.com/.../overview-microsoft-search-bing
173  : https://www.webnots.com/how-to-remove-quick-links-and-news-feeâ€¦
```
## Features

- print/no line numbers.
- remove white spaces/trim/strip.
- exclude search/inverse
- more functionality will be added and will be updated sooon
- just help us and contribute us.


## Usage/Examples


#### search for a specific word/string. 
```cmd
PS C:\grep> py .\main.py .\test.txt Microsoft
11   : 1. Launch the Microsoft Edge browser on your Windows 11 computer.
16   : How to Remove the Annoying Bing Explore Bar - Microsoft Commuâ€¦
17   : answers.microsoft.com/en-us/microsoftedge/forum/all/how-to-remove-the-annoying-bing-explore-bar/bcdf6e62-b2c6-4a8e-9547-d4e2e80e816c
...
...
...
174  : How to Remove Quick Links and News Feed in Microsoft Edge New ... - WebNots
```



#### exclude which have the 
```cmd
PS C:\grep> py .\main.py .\test.txt -e " "  
1    : Chats
2    : Plugins
4    : Recents
....
....
....
172  : webnots.com
173  : https://www.webnots.com/how-to-remove-quick-links-and-news-feeâ€¦
```

#### and get help to see other options.
```cmd
PS C:/> grep --help
usage: main.py [-h] [-n] [-s] [-e] filename search

A program similar to Linux grep.

positional arguments:
  filename    Path to the input file.
  search      String to search for.

options:
  -h, --help  show this help message and exit
  -n          Display line numbers.
  -s          Strip leading and trailing spaces.
  -e          exclude the part/string provided.
```
## Authors

- [@h4jack](https://www.github.com/h4jack)


## License

[MIT](https://github.com/h4jack/grep/blob/main/LICENSE/)


## Feedback

If you have any feedback, please reach out to us at ig: @0x07da