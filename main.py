import argparse
import sys
import colorama

# Initialize colorama for cross-platform ANSI color support
colorama.init()

def main():
    parser = argparse.ArgumentParser(description="A program similar to Linux grep.")
    parser.add_argument("filename", help="Path to the input file.")
    parser.add_argument("search", help="String to search for.")
    parser.add_argument("-n", action="store_true", help="Display line numbers.")
    parser.add_argument("-s", action="store_true", help="Strip leading and trailing spaces.")
    parser.add_argument("-e", action="store_true", help="exclude the part/string provided.")

    args = parser.parse_args()

    try:
        with open(args.filename, "r") as file:
            for line_no, line in enumerate(file, start=1):
                if args.s:
                    line = line.strip()  # Remove leading and trailing spaces
                if args.e:
                    if args.search.lower() not in line.lower():
                        highlighted_line = line
                        if args.n and args.s:
                            print(f"{line_no:<4} : {highlighted_line}")
                        elif args.n:
                            print(f"{line_no:<4} : {highlighted_line}", end="")
                        elif args.s:
                            print(highlighted_line)
                        else:
                            print(highlighted_line, end="")
                elif args.search.lower() in line.lower():
                    # Highlight matching words
                    highlighted_line = line.replace(args.search, f"{colorama.Fore.RED}{args.search}{colorama.Style.RESET_ALL}")
                    if args.n and args.s:
                        print(f"{line_no:<4} : {highlighted_line}")
                    elif args.n:
                        print(f"{line_no:<4} : {highlighted_line}", end="")
                    elif args.s:
                        print(highlighted_line)
                    else:
                        print(highlighted_line, end="")
    except FileNotFoundError:
        print(f"Error: File '{args.filename}' not found.")

if __name__ == "__main__":
    main()
