
# Try


在try{...}的區塊中，若有異常情形時，程式就會離開try的區塊，由後續的一個或多個catch子句判斷需執行何種異常處理。在D、Java、C#及Python程式語言中，try{...}區塊中還可以加入一個finally子句，不管程式流程是否離開try{...}區塊，finally子句中的程式都一定會執行，常用在當程式結束處理時，需要放棄一些外部資源（檔案或資料庫連結）的情形下：

FileStream stm = null;                    // C# example
try {
    stm = new FileStream ("logfile.txt", FileMode.Create);
    return ProcessStuff(stm);             // may throw an exception
} finally {
    if (stm != null)
        stm. Close();
}

由於上述情形相當普遍，C#提供一種特殊的語法進行相同的處理：

using (FileStream stm = new FileStream ("logfile.txt", FileMode.Create)) {
    return ProcessStuff(stm);             // may throw an exception
}

只要離開 using區塊，編譯器會自動釋放stm物件，Python的 with指令及也有類似的功能。

這些語言都有定義標準的異常情形及其出現的條件，程式設計者也可以丟出自己產生的異常（其實C++及Python的throw和catch支援絕大多數形態的物件）。

若某一個throw指令找不到對應的catch，控制流程會離開目前的副程式或控制結構，設法找到對應的catch，若到主程式的結尾還是找不到對應的catch，程式會強制結束，並顯示適當的錯誤訊息。 

# C 標準函式庫（C standard library，缩写：libc）是在C語言程式設計中，所有符合標準的头文件（head file）的集合，以及常用的函式庫實作程序（如 I/O 輸入輸出和字串控制）。不像 COBOL、Fortran 和 PL/I等程式語言，在 C 語言的工作任務裡不會包含嵌入的關鍵字，所以幾乎所有的 C 語言程式都是由標準函式庫的函式來建立的
