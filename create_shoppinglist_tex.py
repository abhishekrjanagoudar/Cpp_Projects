import os
import re

tex_preamble = r'''% ShoppingList_All.tex - Combined source listing
\documentclass[9pt,twocolumn]{article}
\usepackage[utf8]{inputenc}
\usepackage[a4paper,top=0.2in,bottom=0.2in,left=0.3in,right=0.3in]{geometry}
\usepackage{xcolor}
\usepackage{courier}
\usepackage{listings}
\usepackage{hyperref}
\usepackage{titlesec}
\titlespacing*{\section}{0pt}{1pt}{1pt}

% Color scheme
\definecolor{kwcolor}{RGB}{0,0,180}
\definecolor{commentcolor}{RGB}{0,120,0}
\definecolor{stringcolor}{RGB}{180,0,0}
\definecolor{bg}{RGB}{248,248,248}

\lstset{
  backgroundcolor=\color{bg},
  language=C++,
  basicstyle=\scriptsize\ttfamily,
  lineskip=-1.5pt,
  keywordstyle=\color{kwcolor}\bfseries,
  commentstyle=\color{commentcolor}\itshape,
  stringstyle=\color{stringcolor},
  numberstyle=\tiny\color{gray},
  numbers=left,
  stepnumber=1,
  numbersep=8pt,
  tabsize=4,
  breaklines=true,
  showstringspaces=false,
  frame=single,
  captionpos=b
}

\begin{document}

\section*{C++ Symbols \& Syntax}
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{\texttt{::}} Access class statics (\texttt{Bank::AccountType}).
    \item \textbf{\texttt{->}} Access object member via ptr (\texttt{p->m()}).
    \item \textbf{\texttt{*}} Declares ptr OR gets value at address.
    \item \textbf{\texttt{\&}} Declares reference OR gets address.
    \item \textbf{\texttt{this}} Pointer to current object instance.
    \item \textbf{\texttt{const}} Immutable; cannot modify the object.
    \item \textbf{\texttt{virtual}} Method can be overridden by child class.
    \item \textbf{\texttt{override}} Safely overrides a virtual method.
    \item \textbf{\texttt{= 0}} Pure virtual method; class is abstract.
\end{itemize}

\section*{STL Containers}
\textbf{\texttt{std::map<K,V>}} -- \textit{Sorted Key-Value Pairs}
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Unique keys, fast key-based search.
    \item \textbf{Actions}: \texttt{m[k]=v}, \texttt{m.erase(k)}
    \item \textbf{Search}: \texttt{if(m.find(k) != m.end())}
    \item \textbf{Iter}: \texttt{for(auto\& p : m) p.first;}
\end{itemize}

\textbf{\texttt{std::vector<T>}} -- \textit{Dynamic Array}
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Fast random access \texttt{v[idx]}, contiguous.
    \item \textbf{Actions}: \texttt{v.push\_back(val)}, \texttt{v.erase(it)}
\end{itemize}

\textbf{\texttt{std::list<T>}} -- \textit{Doubly Linked List}
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Fast insert/erase anywhere, NO \texttt{v[idx]}.
    \item \textbf{Actions}: \texttt{l.push\_back(val)}, \texttt{l.remove(val)}
\end{itemize}

\section*{Pointer Types \& Memory}
\textbf{1. \texttt{unique\_ptr<T>}} (Exclusive)
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Auto-frees memory on scope exit. No leaks.
    \item \textbf{Syntax}: \texttt{auto p = std::make\_unique<T>();}
    \item \textbf{Pass}: Cannot copy. Transfer via \texttt{std::move(p)}.
\end{itemize}

\textbf{2. \texttt{shared\_ptr<T>}} (Shared)
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Ref-counted. Auto-frees when last owner dies.
    \item \textbf{Syntax}: \texttt{auto p = std::make\_shared<T>();}
\end{itemize}

\textbf{3. Raw Pointers \texttt{T*}} (Non-owning)
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Use}: Observe existing objects. Avoid memory leaks!
    \item \textbf{Pass}: \texttt{uptr.get()} passes raw without moving.
\end{itemize}

\section*{OOP Concepts}
\begin{itemize}
    \setlength\itemsep{-0.3em}
    \item \textbf{Construct}: Base constructs first, then Derived.
    \item \textbf{Destruct}: Derived destructs first, then Base.
    \item \textbf{Polymorphism}: Base ptr runs Derived virtual method.
\end{itemize}
'''

ordered_files = [
    "Product.cpp",
    "Item.cpp",
    "ShoppingList.cpp",
    "Discount.cpp",
    "NoDiscount.cpp",
    "FixedDiscount.cpp",
    "QuantityDiscount.cpp",
    "ShopDb.cpp",
    "Shop.cpp",
    "tests.cpp",
    "main.cpp"
]

def clean_cpp_code(code):
    # Remove block comments
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    # Remove single line comments
    code = re.sub(r'//.*', '', code)
    # Remove empty lines
    lines = [line.rstrip() for line in code.split('\n')]
    cleaned_lines = [line for line in lines if line.strip() != '']
    return '\n'.join(cleaned_lines)

work_dir = r"E:\Abhishek_Git\Cpp_Projects\Exam-2023WiSe_ShoppingList\myCode"
out_file = os.path.join(work_dir, "ShoppingList_All.tex")

with open(out_file, 'w', encoding='utf-8') as f_out:
    f_out.write(tex_preamble + '\n')
    
    for filename in ordered_files:
        filepath = os.path.join(work_dir, filename)
        if os.path.exists(filepath):
            with open(filepath, 'r', encoding='utf-8') as f_in:
                code = f_in.read()
            cleaned_code = clean_cpp_code(code)
            
            f_out.write(f"\n\\section*{{{filename}}}\n\\begin{{lstlisting}}\n")
            f_out.write(cleaned_code)
            f_out.write("\n\\end{lstlisting}\n")
            
    f_out.write("\n\\end{document}\n")

print(f"Generated {out_file}")
