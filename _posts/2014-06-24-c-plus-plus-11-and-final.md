---
layout: post
title: C++11 and `final`
date: 2014-06-24 17:50
comments: true
tags: [c++,c++11]
---

## lesser

Adjective

    comparative form of little: more little
    Of two (or, rarely, more than two) things: the smaller in size (littler), in value, in importance etc. 

    Antonym: greater
    lesser panda, lesser yellowlegs

Noun (plural lessers)

    a thing that is of smaller size, value, importance etc.

        the lesser of two evils
        The greater sand hills increasingly do not migrate, but almost all lessers do.


- https://en.wiktionary.org/wiki/lesser




C++11 addition of the `final` keyword essentially mirrors the `final`
feature in Java, which has existed since its inception.

The `final` keyword in C++11 can be applied to either an entire class or a
method.  When applied to a class, it signifies that the class is *closed to
derivation*; that is, you cannot create a class derived from a `final`
class.

The second way is when applying `final` to a method, which prevents the
method from being overridden by a derived class (though it is still possible
to create subclasses).

# How do you declare a `final` class?

Given a base class and a derived class, you would normally write:

{% highlight c++ %}
class Base0
{
};

class Derived0 : Base0
{
};
{% endhighlight %}

However, if you wish to prevent the base class from being subclassed, simply
add `final` after the classname, thus:

{% highlight c++ %}
class Base1 final
{
};

// Error!
class Derived1 : Base1
{
};
{% endhighlight %}

If you try to compile this code, you will get the error:

{% highlight bash %}
finalclass.cpp:16:18: error: base 'Base1' is marked 'final'
class Derived1 : Base1
                 ^
finalclass.cpp:12:7: note: 'Base1' declared here
class Base1 final
      ^
1 error generated.
{% endhighlight %}

The compiler specifically prevents any subclassing of `Base1` with a hard
error.

# How do you declare a `final` method?

It is also possible to mark an indvidual method as `final`.  The method must
be `virtual` to begin with, and making it `final` prevents it from being
overriden in a derived class.

(If the method isn't virtual, you would be effectively creating a shadow
method that overrides the base method.)

Take the following simple example of a derived class overriding a virtual
function declared in the base:

{% highlight c++ %}
class Base0
{
    virtual void foo();
};

class Derived0 : Base0
{
    void foo();
};
{% endhighlight %}

This compiles and works just fine.  But if we wanted to ensure that the
method was not reimplmented in any derived classes (For example, to preserve
important behaviour), simply adding the `final` modifier at the end of the
method declaration.  So given the following example:

{% highlight c++ %}
class Base1
{
    virtual void foo() final;
};

class Derived1 : Base1
{
    // Error!
    void foo();
};
{% endhighlight %}

the compiler gives us the following error:

{% highlight bash %}
finalmethod.cpp:21:10: error: declaration of 'foo' overrides a 'final' function
    void foo();
         ^
finalmethod.cpp:16:18: note: overridden virtual function is here
    virtual void foo() final;
                 ^
1 error generated.
{% endhighlight %}

金融監督管理委員會在2019年中發布金管證發字第1080321164號函令（下稱「金管會令」，將虛擬通貨中具投資性質者，核定為「證券交易法下的有價證券」


    BUSD 的儲備資金充足，資金託管安全，用戶不用擔心提現問題；
    SEC 認定 BUSD 為未註冊證券，突破了現有 Howey Test 的範圍，或重新定義加密監管；
    穩定幣原本應由美國財政部監管，這一監管也涉及管轄權之爭；
    Paxos 的穩定幣產品矩陣中 USDP 和 PAXG 尚未受到監管打擊，SEC 針對 BUSD 實際上是針對幣安。

上週開始流言蜚語不斷的 Paxos 正式面臨監管機構的前後夾擊。除了受紐約金融服務部（NYDFS）調查後，Paxos 被命令停止發行新 BUSD 代幣，其又因穩定幣 BUSD 收到美國 SEC 的「威爾斯通知（Wells notice）」，部分用戶已收到重新進行 KYC 驗證或關閉帳戶的通知。

 PANews   /   2023-02-14



BUSD 是由 Paxos 信託公司發行並託管的一種美元擔保的穩定資產，供應量按 1:1 的比率與美元掛鉤，由紐約州金融服務部監管。

Nansen 數據顯示，目前 BUSD 總市值 160 億美元，排名穩定幣第三，僅次於 USDT 和 USDC。其中，幣安是使用 BUSD 最多的加密交易平台，約 90%（144 億美元）的 BUSD 由幣安地址持有。而在過去 7 天，幣安淨流出超 8140 萬枚 BUSD。

但 NYDFS 已要求 Paxos Trust Co. 停止發行更多的 BUSD 代幣。根據幣安的聲明，Paxos 將繼續管理 BUSD 的贖回，BUSD 的市值只會隨著時間的推移而下降。Paxos 將繼續為該產品提供服務，管理贖回，並將根據需要提供額外的資訊。

BUSD 是否會出現擠兌危機？實際上，BUSD 的儲備資金除了少量美元現金，其他大部分都是風險較小的美國國庫券和美國國債抵押逆回購協議組成。而據 ChainEye 數據顯示，BUSD 的儲備淨資產市值為 226.5 億美金（截至 2022.11 報告），超過今日（2 月 13 日）161.7 億美元的流通量。

不過，因被認定是未註冊的證券被美國 SEC 執法人員發出了一封名為「威爾斯通知」的信函。作為 BUSD 的美元託管方和發行方，也是穩定幣 USDP 的發行人及加密交易所 itBit 的幕後推手，目前 Paxos 已通知部分用戶重新進行 KYC 驗證或關閉帳戶，並在向用戶發送的郵件中表示，「Paxos 是一家受監管的金融機構，法律要求我們對客戶有更深入的了解，以便保持準確和最新的記錄。」對於那些被要求關閉帳戶，Paxos 則表示其目前無法維護帳戶，原因在於用戶提供的帳戶資訊或帳戶活動超出了該公司的風險偏好。

但 Paxos 仍有辯解推翻執法行動的機會。其實，威爾斯通知是美國 SEC 執法部門對在美上市公司進行民事訴訟前發出的非正式提醒，一旦公司接到通知，必須在 30 天內進行回應和協商，包括證明為什麼不應對潛在被告提出指控的論據，除非得到 SEC 批准延期。若執法人員依舊認定為該公司違反相關證券法規，則會向 SEC 建議提起執法行動，再由 SEC 委員開會表決是否通過。也就是說，如果 Paxos 不能說服 SEC，要想全身而退的可能性幾乎等於零難，最後往往不得不繳納高昂罰金來「和解」。

在一些業內人士看來，SEC 表面針對的是 Paxos 和 BUSD，實際上是針對的幣安。一方面 Paxos 發行的穩定幣中除了 BUSD 還有另一個美元穩定幣 USDP（近 9 億市值）和黃金穩定幣 PAXG（近 5 億市值），這兩個都沒有明確消息遭到監管。而如果切斷了 BUSD 這個合規的出入口，就意味著阻斷了幣安部分合規的出入金。值得一提的是，幣安從 2 月 8 日開始，也暫時暫停通過銀行帳戶存取美元。有人解讀稱，這或許是一場針對幣安監管的「前戲」。

對此，幣安創辦人 CZ 回應稱，除了公開新聞文章外，該消息沒有任何相關資訊。該訴訟是在美國證券交易委員會和 Paxos 之間進行的。「如果」BUSD 被法院裁定為證券，它將對加密產業在被裁定為此類的司法管轄區內如何發展（或不發展）產生深遠影響。Binance 將在可預見的未來繼續支持 BUSD。我們確實預見到用戶會隨著時間的推移遷移到其他穩定幣。我們將相應地進行產品調整。例如，不再使用 BUSD 作為交易的主要貨幣對等。鑑於某些市場持續的監管不確定性，幣安將審查這些司法管轄區的其他項目，以確保用戶免受任何不當傷害。
穩定幣被認定證券？或引發新一輪監管爭奪戰

SEC 起訴 Paxos 違反投資者保護法的理由是其 BUSD 被認定為未註冊證券。根據聯邦證券法要求，所有證券的發行和銷售，需根據其規定進行登記，除非獲得豁免註冊的資格。

而證券法本身對證券的定義較為廣泛，主要依據於美國最高法院對 1933 年和 1934 年證券法的解釋，包括股票、票據、債券、其它典型的股權和債務工具；任何形式的投資合同。作為直屬美國聯邦的獨立準司法機構，SEC 負責美國的證券監督和管理工作，是美國證券產業的最高機構，通常採用 Howey Test 這一有效手段判斷一項發行物是否屬於證券並進行監管。Howey Test 適用於任何合同、計劃或交易，無論其是否具有典型證券的任何特徵，主要包括四個要件：是否存在資金投資；是否投資於共同事業；是否存在對投資利益的期待；是否依賴第三方的努力獲得利益。

過去，不少加密項目均因非法證券發行而被 SEC 起訴，大部分通常選擇繳納巨額罰款與其和解。但相比其他類型的加密貨幣，BUSD 作為錨定美元這一價值穩定資產的加密貨幣，並不存在投資人有收益預期的可能性，顯然不符合 Howey Test 的特徵，就算是 BUSD 持有者間接持有了債券這個有價證券，但他們也並未從中獲益。

不過，SEC 採用的 Howey Test 一直被認為有著一定的局限性。比如美國 SEC 委員 Hester Peirce 曾表示，Howey Test 可能不適用於加密貨幣，SEC 需要更清楚，因為很多加密資產具有自己獨特的特性。所以 SEC 似乎正在重新定義針對加密項目的「Howey Test」。

不僅如此，從以往監管方面來看，由於穩定幣因背後錨定的是法幣而被視為貨幣，通常是由美國版「銀監會」——隸屬於美國財政部的貨幣監理署（OCC）管理。一直以來，OCC 對穩定幣的監管較為友好，包括允許受聯邦監管的銀行可以使用穩定幣進行支付和其他活動等。OCC 代理署長 Michael Hsu 曾就穩定幣監管的必要性表示，像監管銀行一樣監管穩定幣發行方可以促進加密產業的創新蓬勃發展，雖然創新在不確定的環境中會茁壯成長，但堅實的基礎可以提供幫助，特別是在涉及資金和信任的時候。他還敦促監管者同行不要急於對加密進行監管，需加強跨部門的努力，即使被視為「反創新者」，也不能為了「過度適應」該產業而降低監管標準。

然而，隨著 SEC 在穩定幣監管上發力，或將引發管轄權之爭，而不同監管機構對加密貨幣的定義存在著很大的差異。此前，SEC 就與商品期貨交易委員會（CFTC）爭奪加密資產監管權爭論不休，雙方為此還達成了一項正式協議來避免加密貨幣監管漏洞。

而穩定幣監管方面或將引發新一輪監管拔河，比如 USDT 發行方 Tether 就分別向紐約州總檢察長辦公室（NYAG）和 CFTC 支付罰款來解決指控。不過，隨著未來《負責任金融創新法案》的出台，金融監管機構對數字資產的管轄權長期存在的不確定性或將得到解決。

值得一提的是，SEC 對 Paxos 的監管正引發加密社群的強烈不滿，比如 Messari 創辦人 Ryan Selkis 發推文稱：「我人生的新目標是結束 Gary Gensler（美國證券交易委員會主席）的政治生涯，讓他成為拜登連任失敗的原因。我將與 Brian（Coinbase 執行長 Brian Armstrong）、Jesse（Kraken 創辦人 Jesse Powell）以及其他數十人一起，他們花了 10 年時間，讓美國處於主導地位，贏得下一個主要的技術前沿。我將花費我所擁有的每一分精力、金融和政治資本來打擊加密貨幣的道德敗壞和腐敗的敵人。明智的監管很重要。事實上的禁令將遭到無情的打擊。」



中芯国际是中国唯一能够量产14纳米FinFET工艺的企业，N+1和N+2工艺都是基于14纳米FinFET工艺改进而来，并且基于DUV光刻机实现的，绕开了美国的禁令。（目前最先进的制程需要EUV光刻机）

中芯国际并没有公开表示N+1和N+2是7nm工艺，但是芯片行业普遍认为，N+1工艺相当于7纳米LPE（低功耗）工艺，N+2工艺相当于7纳米LPP（高性能）工艺。


證券法中最重要的關於證券的定性標準 —— 豪威測試（Howey Test），為判斷各類加密貨幣是否應該被視為證券提供參考。



1933 年的《證券法》是關於公司從公眾籌集資金的。投資者可以決定承擔哪些風險；向公眾發行證券的公司必須向公眾提供全面、公平和真實的資訊披露，以保護投資者的權益。羅斯福將這部法律稱為「證券真相法」。

1934 年，國會通過了《證券交易法》。該法規涵蓋了中介機構，例如交易所本身和經濟自營商。基本思想是，公眾不僅在證券最初發行時，而且在證券在二級市場交易時，都應該得到披露和保護。

1940 年，國會通過了《投資公司法案》和《投資顧問法案》，要求基金和顧問必須進行註冊，以管理他人的資金，並防止存在更多的利益衝突機會。

美國 1933 年《證券法》與 1934《證券交易法》對證券的定義十分廣泛，既包括了一般意義上用於投資的證券，比如股票、債券，也包括了多種非標準的證券，如「收益證明或參與收益共享安排證明」、「投資合約」以及「一般而言，被普遍認為是證券的所有收益或工具」。




測試（Howey Test）是 1946 年美國聯邦最高法院審理的美國證監會起訴豪威公司（SEC v. WJ Howey Co.）案中使用的一種判斷特定交易是否構成證券發行的標準。

豪威公司是美國佛羅里達州的一家房地產公司，它開發了大片的橘子園，並將一般的土地出售給投資者。該公司在與投資者簽署土地買賣合約的同時，又和投資者簽了一份管理服務合約，即將所售出的土地交由被告公司進行管理。

在豪威測試中符合的要件越多，說明特定交易的屬性越接近證券。
（1）金錢投資（Investment of Money）

該要件要求購買者通過現金作為對價形式，向專案發起方提供資金。
（2）投資於共同事業（Common Enterprise）

該要件旨在區分投資合約與一對一的私人合約。針對該要件，最高法院要求共同事業須具有「橫向共性」「廣泛縱向共性」和「狹義縱向共性」。

    「橫向共性」要求通過資金彙集，將每個投資者的財富與其他投資者的命運捆綁在一起，通常與按比例分配利潤相結合；
    「廣義縱向共性」要求投資者能否獲得收益取決於專案發起人的努力；
    「狹義縱向共性」要求投資者的收益、他人的努力均與最終的經營成果相結合。

（3）投資人有收益預期（Expectation of Profit）

這裡的「收益」可以是初始投資或經營事業而產生的資本增值，或者應使用買方資金而產生的收益。完全藉助外部市場力量（如一般通貨膨脹趨勢或經濟發展）影響基礎資產的供求而產生的價格增值，不屬於豪威測試下的「收益」。
（4）收益僅來自他人的努力（Derived From The Efforts of Others）

該要件要求專案發起方、組織方或者其他關聯第三方進行了必要的管理努力，並且該努力將關鍵性地影響事業的成功，投資者僅需付出指定的費用及成本，並不實際參與專案的運營和管理。


要求「共同事業」，是由於最高法院認為在「共同事業」的場景下，由於個體進行盡職調查和溝通的成本較高，單個投資者沒有動力通過與其他投資者協調來獲取資訊，也無法阻止集體和專案發起方進行談判，因此投資人只能完全依賴發起方獲得收益，發起方在專案中具有舉足輕重的作用，與投資人之間形成不平等地位。

為彌補這種力量懸殊，將投資合約界定為證券更有利於投資人評估定價投資專案，保護投資者利益。又如標準四中明確「他人的努力」，目的在於明確投資合約的責任主體，在落實證券披露義務時，能夠準確定位資訊披露義務人。



證券交易委員會（SEC）與加密貨幣

2019 年 4 月 3 日，美國證券交易委員會（SEC）基於豪威測試釋出了一份數位資產投資合約分析框架，為判斷數位貨幣是否屬於證券提供了官方指導。 SEC 認為，目前市面上大多數的數位貨幣都滿足「有資金投入」和「投資於一個共同事業」這兩項標準。

對於另外兩個標準，美國證交會指出，如果數位貨幣的發展依賴某公司或中心化實體的努力，並且購買者存在從投資中獲得合理利潤的預期，那麼這種數位貨幣就被視為證券。需要指出的是，如果某種數位貨幣的去中心化程度足夠高，有明確的應用場景，並且價格變化與應用情況相關而不是來自投資者對利潤的預期，那麼這種數位貨幣就不屬於證券。美國證交會已經表示比特幣和以太坊不屬於證券。[2]
3.1  BTC

美國證券交易委員會（SEC）前金融司司長 Bill Hinman 於 2018 年的演講中指出 比特幣（BTC）並非證券，歸商品期貨交易委員會（CFTC）監管 。CFTC 主要負責監管衍生品市場，包括期貨、掉期和某些種類的期權。這也呼應了 BTC 挖礦像黃金、石油等大宗商品一樣。
3.2  ETH

3.2.1  ETH（ICO）

以太坊初始代幣發行（ICO）始於 2014 年 8 月，為期 42 天的 ICO 募資 31000 枚比特幣，售出以太幣 60,102,216，以當時的匯率，約合 1840 萬美元。 從這段 ICO 的歷史來看，它應該被歸屬為證券。

3.2.2  ETH（PoW）

以太坊的 POW 階段與比特幣類似。

3.2.3  ETH（PoS）

以太坊於 2022 年 9 月 15 日完成主網和信標鏈合併，共識機制轉為權益證明（PoS）。PoS 的運作流程是，質押者將 32 個 ETH 放入智慧合約中，並同時收到一個憑證，用於證明 Staking 的提取權。

由此可見，第一，智慧合約並沒有使用這 32 個 ETH，在投資的情況下，公司會將這筆資產花掉，投入生產。由於提取證明的存在，所有質押者的身份都是可識別的，不是一個繫結的命運共同體，也不具備「橫向共性」的特徵。第二，Staking 收益是由 PoS 演算法發放的，而不是由服務提供者（例如 Coinbase）發放的，因此收益並非來自他人的努力。如果將其看作投資，應該將 ETH 交給驗證節點，驗證節點通過將這些資產投入生產獲得收益，然後將部分收益分給質押者。
3.3  穩定幣（Stablecoins）

2 月 14 日，美國證券交易委員會（SEC）執法人員向 BUSD 穩定幣發行商 Paxos 釋出「韋爾斯通知」（Wells notice），當日下午，紐約州金融服務部命令 Paxos Trust Co. 停止發行更多的 BUSD Token。

關於加密貨幣穩定幣，現任 SEC 主席 Gary Gensler 在 2022 年 9 月 8 日的演講中提到，穩定幣具有與貨幣市場基金、其他證券和銀行存款相似和可能與之競爭的特徵，並將引發重要的政策問題。重要的是要確保我們有合適的投資者保護和防止非法活動的保障措施。

穩定幣主要用作參與加密平臺的手段，或用作加密平臺內部的結算代幣。它們是否屬於貨幣市場基金的股份或其他型別的證券，取決於它們的屬性，例如這些工具是否通過關聯公司或其他方式直接或間接支付利息；使用什麼機制來維持價值；或者代幣在加密生態系統中的提供、銷售和使用方式。
3.4  其它 Token

美國證券交易委員會（SEC）主席 Gary Gensler 多次表示， 大多數的虛擬資產都是證券。

其以 1990 年美國最高法院法官 Thurgood Marshall 一份判決意見書為佐證：當有人從大眾募集資金，且大眾參與其利潤，就屬於證券。SEC 針對這些被認為是證券的虛擬資產進行監管，包括要求發行者遵守證券法規定的資訊披露和註冊要求，以確保投資者能夠獲得足夠的資訊來做出明智的投資決策。此外，SEC 還對虛擬資產市場中存在的欺詐和操縱行為進行監管，以保護投資者的權益。
四、Staking 是證券嗎？

Coinbase 認為 Staking 不符合豪威測試的四個條件。

    質押服務不構成金錢投資，質押者完全保留其資產的完全所有權；
    質押服務的提供者不是普通企業，整個過程是在去中心化網路上通過智慧合約執行的；
    質押獎勵是對區塊鏈驗證提供者的工資，而不是投資回報，不屬於「合理的利潤預期」；
    質押服務的提供者僅使用公開的軟體和電腦執行驗證服務，不執行任何管理工作，這些是 IT 服務，而不是投資服務，所以不是依據「他人的努力」支付獎勵。

證券法的目的是糾正資訊不對稱，保護投資者的合法權益。但是在質押中不存在資訊不對稱，因為所有參與者都在公開透明的區塊鏈上，有對相同資訊平等的訪問許可權來驗證交易。試圖將證券法強加到質押這樣的環節對使用者一點幫助都沒有。相反，不必要的激進授權將阻止使用者訪問基本的加密服務，並將他們推向離岸、不受監管的平臺。

證券交易委員會（SEC）與加密貨幣

2019 年 4 月 3 日，美國證券交易委員會（SEC）基於豪威測試釋出了一份數位資產投資合約分析框架，為判斷數位貨幣是否屬於證券提供了官方指導。 SEC 認為，目前市面上大多數的數位貨幣都滿足「有資金投入」和「投資於一個共同事業」這兩項標準。

對於另外兩個標準，美國證交會指出，如果數位貨幣的發展依賴某公司或中心化實體的努力，並且購買者存在從投資中獲得合理利潤的預期，那麼這種數位貨幣就被視為證券。需要指出的是，如果某種數位貨幣的去中心化程度足夠高，有明確的應用場景，並且價格變化與應用情況相關而不是來自投資者對利潤的預期，那麼這種數位貨幣就不屬於證券。美國證交會已經表示比特幣和以太坊不屬於證券。[2]
3.1  BTC

美國證券交易委員會（SEC）前金融司司長 Bill Hinman 於 2018 年的演講中指出 比特幣（BTC）並非證券，歸商品期貨交易委員會（CFTC）監管 。CFTC 主要負責監管衍生品市場，包括期貨、掉期和某些種類的期權。這也呼應了 BTC 挖礦像黃金、石油等大宗商品一樣。
3.2  ETH

3.2.1  ETH（ICO）

以太坊初始代幣發行（ICO）始於 2014 年 8 月，為期 42 天的 ICO 募資 31000 枚比特幣，售出以太幣 60,102,216，以當時的匯率，約合 1840 萬美元。 從這段 ICO 的歷史來看，它應該被歸屬為證券。

3.2.2  ETH（PoW）

以太坊的 POW 階段與比特幣類似。

3.2.3  ETH（PoS）

以太坊於 2022 年 9 月 15 日完成主網和信標鏈合併，共識機制轉為權益證明（PoS）。PoS 的運作流程是，質押者將 32 個 ETH 放入智慧合約中，並同時收到一個憑證，用於證明 Staking 的提取權。

由此可見，第一，智慧合約並沒有使用這 32 個 ETH，在投資的情況下，公司會將這筆資產花掉，投入生產。由於提取證明的存在，所有質押者的身份都是可識別的，不是一個繫結的命運共同體，也不具備「橫向共性」的特徵。第二，Staking 收益是由 PoS 演算法發放的，而不是由服務提供者（例如 Coinbase）發放的，因此收益並非來自他人的努力。如果將其看作投資，應該將 ETH 交給驗證節點，驗證節點通過將這些資產投入生產獲得收益，然後將部分收益分給質押者。
3.3  穩定幣（Stablecoins）

2 月 14 日，美國證券交易委員會（SEC）執法人員向 BUSD 穩定幣發行商 Paxos 釋出「韋爾斯通知」（Wells notice），當日下午，紐約州金融服務部命令 Paxos Trust Co. 停止發行更多的 BUSD Token。

關於加密貨幣穩定幣，現任 SEC 主席 Gary Gensler 在 2022 年 9 月 8 日的演講中提到，穩定幣具有與貨幣市場基金、其他證券和銀行存款相似和可能與之競爭的特徵，並將引發重要的政策問題。重要的是要確保我們有合適的投資者保護和防止非法活動的保障措施。

穩定幣主要用作參與加密平臺的手段，或用作加密平臺內部的結算代幣。它們是否屬於貨幣市場基金的股份或其他型別的證券，取決於它們的屬性，例如這些工具是否通過關聯公司或其他方式直接或間接支付利息；使用什麼機制來維持價值；或者代幣在加密生態系統中的提供、銷售和使用方式。
3.4  其它 Token

美國證券交易委員會（SEC）主席 Gary Gensler 多次表示， 大多數的虛擬資產都是證券。

其以 1990 年美國最高法院法官 Thurgood Marshall 一份判決意見書為佐證：當有人從大眾募集資金，且大眾參與其利潤，就屬於證券。SEC 針對這些被認為是證券的虛擬資產進行監管，包括要求發行者遵守證券法規定的資訊披露和註冊要求，以確保投資者能夠獲得足夠的資訊來做出明智的投資決策。此外，SEC 還對虛擬資產市場中存在的欺詐和操縱行為進行監管，以保護投資者的權益。
四、Staking 是證券嗎？

Coinbase 認為 Staking 不符合豪威測試的四個條件。

    質押服務不構成金錢投資，質押者完全保留其資產的完全所有權；
    質押服務的提供者不是普通企業，整個過程是在去中心化網路上通過智慧合約執行的；
    質押獎勵是對區塊鏈驗證提供者的工資，而不是投資回報，不屬於「合理的利潤預期」；
    質押服務的提供者僅使用公開的軟體和電腦執行驗證服務，不執行任何管理工作，這些是 IT 服務，而不是投資服務，所以不是依據「他人的努力」支付獎勵。

證券法的目的是糾正資訊不對稱，保護投資者的合法權益。但是在質押中不存在資訊不對稱，因為所有參與者都在公開透明的區塊鏈上，有對相同資訊平等的訪問許可權來驗證交易。試圖將證券法強加到質押這樣的環節對使用者一點幫助都沒有。相反，不必要的激進授權將阻止使用者訪問基本的加密服務，並將他們推向離岸、不受監管的平臺。[3]


傭兵組織「瓦格納集團」首腦普里格津（Yevgeny Prigozhin）

據 BeIn Crypto 報導，網路上開始盛傳，普里格津生前掌控著持有大量比特幣的錢包，該錢包據稱持有約 10 萬枚比特幣，價值約 26 億美元，其中約 70% 存放在冷錢包中，其餘部分分布在幣安和 BTC-W 之中。

bitinfocharts 的比特幣持有量排行榜顯示，目前持有比特幣最多的是幣安的一個冷錢包地址，持有量達 248,597 枚，而如果普里格津果真持有 10 萬枚比特幣的話，他將躍升前 5 大比特幣巨鯨，超越當前擁有 94,643 枚比特幣的第 5 大錢包地址。




比特幣創造者中本聰的匿名身份是「沒有可信第三方的金融神話創造的一部分」，是一種在網路上轉移價值的新方式，其目標是沒有政府監督或銀行等中介機構。但自古以來，金融世界就建立在信任和法治之上。此外，從銀行到證券交易所，金融已經趨向於中心化和相互關聯。加密貨幣市場也不例外，有許多宣稱「值得信賴」但不合規的中介機構。

    如今，加密貨幣由少數交易、借貸、質押和其他金融中介機構主導，一些數據顯示，三大加密交易平台據稱佔所有交易量的近四分之三。

缺乏合規性會使投資者來之不易的資產面臨風險，投資者缺乏關於加密資產本身以及執行交易和資產託管公司的基本資訊披露。

    從本質上講，這些公司是在說「相信我們」。 更重要的是，當加密公司破產時，他們會求助於破產法庭來解決他們的爛攤子。 考慮到中本聰的最初設想 ——「程式碼就是法律」，這有點諷刺。





     

台灣金管會擬發布「具證券性質之數位代幣」之認定標準，並規劃將STO納入證券交易法規範

首先，金管會於2019年4月12日公聽會上表示，擬規劃發布命令核定「具證券性質之數位代幣」(下稱證券型代幣)為證券交易法第6條所稱之有價證券。至於何謂「證券型代幣」？金管會參酌美國判定「投資契約」之標準(即Howey Test)，表示「證券型代幣」係指透過加密保護並表彰持有人得收取利益之憑證，且具流通性及下列投資性質者：(一)投資人出資、(二)出資於一共同事業、(三)投資人分享報酬、及(四) 報酬主要取決於發起人或第三人之努力[2]。

金管會擬定之「證券型代幣」標準，在解釋及適用上仍具高度之不確定性，不無可能所有具流通性之代幣均會落入「證券型代幣」之範圍

針對金管會完全照抄美國認定投資契約之要件作為我國有價證券之認定標準，此事是否適宜本已容待討論(此問題將再另以專論探討)；姑且先不論此問題，針對金管會目前提出之認定標準，亦無法有效界定「證券型代幣」之範圍。

參酌金管會提出之標準，僅得以確定的是，不具流通性之代幣應非「證券型代幣」。至於其他具有流通性的代幣是否屬「證券型代幣」，則需進一步判定代幣是否符合其餘四項要件，惟針對這四項要件之解釋及適用，在我國仍未明確。

日前，金管會在公聽會上表示其係參酌美國Howey test訂定前述標準，故不無可能金管會亦會採取與美國SEC在DAO案中對Howey Test要件之解釋方式認定有價證券。美國SEC對Howey Test要件之解釋極為寬鬆，在DAO案中，針對「投資人出資」之要件，SEC認為應包含以任何形式之出資類型，並不限於法定貨幣尚包括加密貨幣，另針對「投資人具獲利之期待」之要件，SEC則認為解釋上包括但不限於「投資人針對獲取股息、定期付款等其他所有未來可能會增值之投資期待」之情形[3]。在如此寬鬆解釋之情況下，尚有美國律師指出「依據前述標準，以太幣亦可能被認定為有價證券[4]」。或許這也可以說明，為什麼至今SEC官方從未公開聲明「以太幣非屬有價證券」。

反觀我國，假設金管會針對這四項要件之解釋及適用完全參酌美國SEC在DAO案中對Howey Test之解釋方式，則合理推論現行所有具流通性之代幣幾乎均有可能落入「證券型代幣」之範疇，包含那些在瑞士、新加坡法令下被歸類為功能型(Utility token)或非屬有價證券(non-securities)之代幣類型，如：ETH、EOS、LTC等。

金管會究竟是否會採取美國SEC之解釋方式？實務上「非證券型代幣」之範圍應如何界定？均仍待金管會進一步闡明，而在這些問題明確前，大部分代幣發行人之法律風險仍無法解除。

針對前述標準之不確定性，僅簡介新加坡MAS之作法供參照

承前，如金管會為有效降低代幣發行人之法令遵循成本、促進產業發展，則需盡速明確化「證券型代幣」之認定標準。具體作法上，以下新加坡MAS目前採行之作法簡單且明確，或可做為我國金管會之參考。

參酌新加坡MAS於2018年11月30日發布之A GUIDE TO DIGITAL TOKEN OFFERINGS[5] (“MAS Guideline”)，為更加明確數位代幣是否屬新加坡證券相關法令規範之有價證券，MAS除闡述證券相關法令關於有價證券之認定標準外，MAS尚例示了11種涉及不同代幣類型之ICO個案，並分別就這11種代幣類型，進一步表示哪幾種類型具備/不具備新加坡證券相關法令規範之有價證券性質。另外，倘業者欲發行之代幣類型有別於列舉之11種類型，MAS亦允許業者在出具有關法律意見書等文件後，直接遞件予MAS以事先確認發行該代幣是否須適用證券相關法令規範。至今，新加坡已成為業界排名最適合發展ICO/STO前五大國家之一




从“Howey检验” 看“投资合同”

董华春 北京大学
　　引子：一个老人的困惑
　　1979年，美国老人Daniel在奔走多年后还是想不明白自己为什么没有资格像同事一样得到那份令人艳羡的养老金。
　　事情起源于他的雇主参与的一份养老金计划。
　　根据该计划涉及的协议，多家雇主为自己所雇用的每位员工向该养老基金每周出资2美元，基金会负责管理基金并在员工退休时以每月75美元的养老金方式付给员工。
　　对于员工来讲，该计划是非自愿性的。员工本人并不需要出资，同时，员工并没有权利选择参加或不参加这份计划，也不能够要求雇主把该项出资直接付给员工本人。
　　该协议规定，员工服务期限必须满20年才有资格享受此收益。Daniel因为工作调整临时下岗了5个月。尽管Daniel四处解释这5个月并不影响他的资格，然而该基金和有关管理部门还是裁定他没有资格享受该计划收益。
　　Daniel只好通过法律途径来为自己挣退休后的“口粮”，他的律师以该基金违反美国1933年《证券法》17 (a)和1934年《证券交易法》第10(b）条和SEC第l0b-5号规则为由起诉。(439 U. S. 551.)
　　让Daniel感到万分困惑的是联邦最高法院认定此处的“养老金计划”并不是“证券”，因而Daniel的主张不能够成立。
　　困惑的不只是Daniel。
　　像面对很多其他证券诉讼案件一样，Daniel一案的律师、SEC、初审法院和联邦最高法院面临着这个绕不开的话题，该“养老金计划”是不是“证券”？究竟什么样的金融工具才构成证券法意义上的证券？
　　一、囊括乾坤的袋子—美国证券法“证券”定义
　　证券法律规范管理的对象是证券和与证券有关的各种行为与活动。也就是说，“除非某项金融工具或交易构成了‘证券’交易，否则，不能适用证券法律”。所以，证券法律在多大范围内被适用，在很大程度上取决于对证券的定义。
　　究竟什么是证券呢？各国证券法有不同的规定。
　　美国国会在1933年《证券法》和1934年《证券交易法》中对“证券”定义的规定相当宽泛。以33年《证券法》第2节（a) (1)为例，证券是指各种票据、股票、国库券、债券、无抵押债券、债务证明、证明参与任何利润共享协议或在其中有利益的证书、担保信托证、筹建经济组织证或认购证、可转让股权、投资合同、委托投票证书、证券存托证明、油矿、气矿或其他矿藏开采权未分配部分的权益；任何证券、存款证明或者组合证券和指数证券（包括根据价格而计算出来的利益）的卖空期权、买空期权、买空卖空期权、选择权或者特权；任何在全国证券交易所上交易的有关外币的卖空期权、买空期权、买空卖空期权、选择权或者特权；或者总的来说，任何被普遍认为是“证券”的利益或工具，或者是对上述项目的任何利益的参与证明、临时性证明、收据、担保或认购权（15 U. S. C.77 b (a) (1)),《证券交易法》第3 (10)条作了几乎完全相同的规定，但特别排除了兑付期不超过9个月的短期商业票据。
　　联邦最高法院认为证券的定义“包含着一条弹性的、但不是呆板的原则，它能够应付那些利用他人钱财、允诺获取利润的人炮制的无穷无尽的、花样翻新的计谋”，这是为了能将“我们这个商品社会中所谓的证券，无论是以怎样的形式出现，都被归纳进定义之中”。于是，证券的定义就变成了一个几乎囊括乾坤的袋子，其广阔空间令从事证券行业的律师们大有可为。
　　然而，袋子再大也是有边界的。美国法院精明的法官们在司法实践当中对证券定义的判断方法并非面面俱到，但对于每一种证券都确定了一套与之相对应的概念和原则。从而一方面限制了律师们错误得把各种金融交易工具纳入“证券”定义而适用证券法律的趋势，另一方面，也使得那些日新月异应该受证券法律管辖的金融交易和工具不能逃脱法律的规范和管理。
　　在Daniel一案中，联邦最高法院认为《证券法》的第2 (a) (1)一条和《证券交易法》3 (a) (10）条在界定证券时都没有明确包括养老基金，因而只能通过“Howey检验”来判定该养老基金是否构成证券定义的一种—“投资合同”。
　　这便涉及到美国证券法上证券定义中的“投资合同”(InvestmentContract）的判定问题。
　　投资合同的定义相当有弹性，类似于证券定义中一个“兜底条款”，其它定义所不能涵盖的“证券”都可以设法联系到这里，根据“Howey检验”判定属于“投资合同”进而属于“证券”。
　　二、投资合同定义的判定—“Howey检验”的提出
　　1946年的SEC v. W. J. Howey Co. (Supreme Court of theUnited States，1946， 328 U.S. 293）一案确立了判定“投资合同”的标准。
　　被告Howey公司是Florida州的一个公司，每年大约种植500亩橘子，将其中一半卖给各地的投资人。Howey公司与投资人签订了“土地销售合同”和“服务合同”，其中约定，土地以保证契约的形式转让给投资人；服务合同期为10年，在合同期间Howey-in-the-Hills Service， Inc．对橘子的播种、收割和销售拥有完整的决策权。卖方既无权进入橘园，也无权拥有任何产品。买卖双方对于土地和产品甚至不是联营，买方只是在收获季节收到一份表示他那一份收益的支票。果园的投资人，即买方居住地距离橘园通常很远，大多不是Florida当地人，以旅游者或居住在一家由Howey公司经营的旅馆中的住户为主；他们大多不具备播种、收割和销售橘子的设备和经验；他们接受合同的唯一理由是希望依赖Howey的经营管理给他们带来利润。
　　双方争议的焦点是“土地销售合同、保证契约、服务合同是否一起构成了《证券法》第2 (a) (1)所指的‘投资合同’，因而属于证券法规范的‘证券’”。
　　SEC认为三者构成了《证券法》下的“投资合同”，因而属于受SEC监管的“证券”；Howey公司没有经过登记就采用“州际商务信函和通讯手段”来发行，违反了《证券法》第5条和第12条．因而提起禁止令诉讼。
　　联邦最高法院认为，判断证券是否存在，不需要找到正式的股票证书，只有存在有形资产的正式收益，例如对橘园的实际拥有就可以了；同时认为应该放弃形式而重视实质，把判断的焦点放在经济现实上（EconomicReality Test)。
　　Murphy法官在判决中考察了“蓝天法”的普遍规定，引用了State v.Gopher Tire＆Rubber Co.（146 Minn. 52， 56， 177 N．W．937，938.）和SEC v. Joiner Corp (320 U.S. 344）的有关原则，提出了一个包括四个要素在内的检验方法，即所谓的“Howey Test” :“证券法律中所谓的投资合同是指在一宗合同、交易或计划中，某人（1)利用钱财进行投资；(2)投资于一个共同企业；(3)仅仅由于发起人或第三方的努力；(4)期望使自己获得利润。”将此标准适用于本案，最高法院支持SEC主张，认为三者构成了《证券法》下定义的“投资合同”进而是“证券”，应按照有关规定登记发行。
　　三、“Howey检验”在实践中的发展
　　（一）利用他的钱财进行投资；
　　最高法院在之后的一个案件中，直截了当的拒绝了投资合同中个人必须以“现金方式”而不是“货物和服务”方式去投资才符合“投资合同”定义得说法，也就是说“只要购买人为了获取具有证券性质的收益而放弃有形的并且确定的权利”，就可以认为是“利用钱财进行投资”，进而满足投资合同的第一个要件。
　　（二）投资于一个共同企业；
　　“共同企业”按照字面的意思是指各个投资人与他们共同投资的项目之间都有类似的关系。
　　“平行的共同关系”要求所有投资者之间有共同关系，这种关系最好的例子就是大众投资人认购发行公司的股份。
　　但是也有一些法院判决“垂直的共同关系”也符合共同企业的定义，即只要求每个投资者与发起者之间有共同利益即可。比如，投资人与其经纪人之间，经纪人可以全权操作投资人的帐户，投资人希望从交易中获取利润，而经纪人希望从帐户的交易中获取佣金。但是，在“垂直的共同关系”这一问题上，法院之间的分歧一直存在。
　　从司法实践经验看，第3、6、 7巡回上诉法院采用“平行的共同关系”，而第5, 11巡回法院采用“垂直的共同关系”，第9巡回法院采用了更加严格的“垂直的共同关系”，即“投资人的财富与第三人的努力相交织并依赖于后者”。
　　（三）仅仅由于发起人或第三方的努力；
　　在SEC v. Koscot Interplanetary， Inc. (United States Court ofAppeals for the Fifth Circuit 1974， 497 F.2d 473）一案中，该公司建立了一种名叫Koscot scheme的金字塔式传销结构，主要来销售化妆品。购买者从自己拉来的客户身上分享提成收益，按揽客量和交易额依次升级为Beauty advisor、 Retail manager和Distributor三个层级，每一级人自动享受下一级人拉来的客户身上所有提成收益。
　　SEC认为这个招聘新人分享收益的金字塔式传销结构构成了33年证券法的“证券”，中的“投资合同”，所以应该登记。
　　初审法院不同意SEC的主张，认为根据Howey检验，投资合同“仅仅（Solely）三方的努力”，而这里，投资人并非没有自己努力，他们参加招募会，寻找新的投资人。
　　第5巡回法院同意SEC的主张，认为“Howey检验”的几个条件都被满足，在判定“仅仅由于发起人或第三方的努力”时必须要从文字上对“仅仅”(Solely）做适当的解释，法官采用了SEC v. Glenn W. turnerEnterprise， Inc. (United States Court of Appeals for the Ninth Circuit，February 1， 1973， 474 F.2d 476）一案中确认的“功能”(functional)判断方法，认为该词语并不意味着完全排除投资者的努力，并不是看投资者有没有努力，而是看其努力是否重要（significant)。在这里，投资者虽然付出了努力，但是其努力只是名义上的（Nominal，不显著的(Insignificant)，因而Howey检验的条件被满足，因而该金字塔式销售计划是“证券”的一种，即“投资合同”。
　　此案和后来的很多案例一起修正了Hwoey检验的这条标准，认为即使买方自己要努力经营，只要他人的努力对业务的成败有重大的影响，而投资者的努力是名义上的（Nominal)或者比例非常小的，这种安排仍然属于投资合同。
　　（四）期望使自己获得利润
　　Howey一案中的利润是购买人在收获季节领取的支票，联邦最高法院在后来的案例中认定利润回报方式不一定是正式的投资利益。当出卖资产时，所期望的利润可以折合成资金，也可以是Howey案件中产品收成带来的收益。
　　尾声：并不成为“投资合同”的养老金计划
　　结合上述分析，返回头来看Daniel一案。
　　初审法院支持Daniel，认为该养老基金实质上创立了Howey案中的“投资合同”，涉及到“证券销售”，所以应该遵守33年《证券法》和34年《证券交易法》的规定。
　　SEC对此发表意见认为该养老基金确实属于证券法规制的证券定义之“投资合同”，但是没有涉及到“证券销售”，因而不能适用34年《证券交易法》的10b和Rulel 0b-5，只适用33年《证券法》12条的有关规定。
　　联邦最高法院则认为该养老金计划不构成“投资合同”。理由是，在此案中，员工所获得的劳务报酬是一份单纯的养老金计划，这一揽子劳务合同中包含的投资意图相对而言是很小的一部分，而且员工本人之所以接受这份工作，也不太可能是（如果有）着眼于未来的养老金投资。法院仔细分析了此案中经济收益的可能性，认为员工出卖自己劳动力的主要目的不是为了投资，因而这份养老金计划并不能构成“投资合同”。
　　然而，如果Daniel -案案情发生变化，比如员工养老金计划是自愿性的，而且需要员工自己至少投资一部分资金（voluntary and contribu-tory investment contract)，那么这样的投资计划算不算是投资合同？
　　笔者翻阅了相关案例，结论并不能确定。SEC解释说“是投资合同”，而有些法院则持异议（Securities Release No.6188， 6281）。
　　看来，尽管美国的法官们构筑了细致的架构，借助“Howey检验”来判定某一金融工具是否为“投资合同”。但是，在适用Howey检验来判定“养老金计划”是否为“投资合同”这一问题上，还有很多工作值得进一步关注和完善。


----



2018年德國聯邦金融監管局發布了《關於區塊鏈技術的監管報告》，將代幣分成三種類型：

1.支付型代幣（Payment Tokens）：例如比特幣、以太幣等，指被用於購買商品及服務或是價值移轉的方式。

2.證券型代幣（Security Tokens）：持有者擁有對特定資產、權益以及債務的所有權，對投資人會允諾未來公司收益或利潤，因此此種代幣之功能類似於證券、債券或其他衍生性金融商品。

3.功能型代幣（Utility Token）：此類型代幣僅應用於發行者自身的網路系統，具有一定程度的封閉性，授權給持有代幣之用戶，利用區塊鏈技術使用產品及服務的權利，或是發行目的在於建立與消費者間更深厚之互動及關係，以建立對品牌或商業體系的忠誠度。此種功能型代幣，本質上並不具備金融商品的屬性，但功能型代幣在實務上有可能具有支付型代幣和證券型代幣的功能，但各國尚未對於此類型狀況進行相關的監管。

本篇文章基於篇幅限制，以下將簡易說明台灣對於證券型代幣相關監管規定。台灣的證券交易法並未對證券型代幣有直接的法條規範，但金管會在2017年發布新聞稿認為「首次代幣發行」(ICO)行為是否屬證券交易法規範之有價證券，視個案情況認定，這也與目前美國證券交易委員會(SEC)、新加坡金融管理局(MAS)及香港證監會就ICO，採個案認定方式管理相同。金管會亦在2019年7月3日以金管證發字第1080321164號令，核定「具證券性質之虛擬通貨為證券交易法所稱之有價證券」，其中「證券性質」的定義，是指兼具流通性及下列「投資」性質： (一)出資人出資； (二)出資於一共同事業或計畫； (三)出資人有獲取利潤之期待； (四)利潤主要取決於發行人或第三人之努力。以上四個判斷標準均須符合。

上述金管會函令是引用美國最高法院於1946年作成的判例（Securities and Exchange Commission v. W. J. Howey Co.,328 U.S. 293 [1946]），一般簡稱為Howey Test。其中值得探討為第三及第四個要件，首先，第三個要件「出資人有獲取利潤之期待」方面，若是僅因外部市場造成供給與需求改變而導致的價格上漲，這在Howey Test認定中並非屬於「利潤」，因此在最近最熱門的NFT（Non-Fungible Token），若投資人看好某個藝術品NFT未來在市場上的價格而決定買入，亦不符合Howey Test第三個要件；另功能型代幣之價值增加主要是來自於代幣持有人及參與者的註冊，此種因代幣持有者及使用者的集體參與行為造成的價值增加，並非取決於發起人或第三人的努力，亦不符合Howey Test的第四個要件。

----

mysqldump -u [UserName] -p[Password] -R [DB_Name] > [DB_Name].sql

mysqladmin -u [UserName] -p[Pasword] create [New_DB_Name]

mysql -u [UserName] -p[Password] [New_DB_Name] < [DB_Name].sql

mysqladmin -u [Username] -p[Password] drop [DB_Name]


Renaming Tables with InnoDB



The InnoDB storage engine is a feature included in all versions of MySQL since MySQL 5.5. It can be used to create a new database, then rename each table from the old database to the new database.

1. Start by creating a new database:

mysql -u [UserName] -p[Password] create [New_DB_Name]

Replace [UserName] with the database username, and [Password] with the password for that account. Replace [New_DB_Name] with any name you’d like.

2. Use a script to rename all the tables in the database:

mysql -u [UserName] -p[Password] [DB_Name] -sNe 
'show tables' | while read table; do mysql -u [UserName] -p
[PassWord] -sNe "RENAME TABLE [DB_Name].$table TO 
[New_DB_Name].$table"; done

The script above cycles through each table in the database and renames it. Provide your password in the script to avoid having to enter it for each cycle.

3. If you have a very small database, you can move the tables manually. This can be less intimidating than running a script, but time-consuming. Start by logging into the MySQL shell:

mysql -u [UserName] -p[Password]

Use the RENAME TABLE command to rename a table:

RENAME TABLE [DB_Name].[Table1] TO New_DB_Name.Table1;

Instead [Table1], type the name of a table in the existing [DB_Name] database. If you have more than one table in this database, you’ll need to repeat this action for each table.




----

Dumping Method

Another way to rename a database in MySQL would be to use the mysqldump shell command. This way, we can create a dumped copy of the database and import the whole database content into the new database. After that, we can drop the old database if that’s necessary.

To start with, we need to dump the old database by running the following command within your shell prompt:

$ mysqldump -u username -p"password" -R oldDbname > oldDbname.sql

The command creates a physical backup that has all database data along with stored procedures and functions.

Following that, we need to use the above-mentioned command to create a new database:

$ mysqladmin -u username -p"password" create newDbname

Finally, we need to import the dump file created in the first step to the new database:

$ mysql -u username -p"password" newDbname < oldDbname.sql

Even though this method appears to be straightforward, it may take considerable time when we deal with a larger database. So, it still leaves much to be desired.

For these reasons, we suggest having a look at the ways to rename a MySQL database more efficiently and conveniently. To illustrate them, we are going to use dbForge Studio for MySQL, an IDE that provides powerful database development, management, and administration capabilities. With its help, we can rename a database in three simple yet effective methods, namely through backup and restore, schema and data comparison, and copy database method.




# Why is `final` useful?

Marking a method or entire class as `final` could be useful if you need to
prevent client code from modifying the behaviour of your base class.  This
may be to enforce 'contractual' behaviour (as in Eiffel; not in a legal
sense!), or it may be to prevent resource management problems.

It should be noted that this is in *no way* a security measure.  This is
purely a compile-time directive to the compiler to enforce the policy, and
has no other effect than to generate an error and stop compiling.  In
attacking any real-world application, a determined cracker would have any
number of mechanisms at their disposal to bypass restrictions that this
might impose.

This information about finality can also be exploited by the compiler to
optimize code, using a technique known as *devirtualisation*. If the
compiler knows it doesn't have to use the vtable (virtual method table) to
dispatch the method call, it can potentially generate more efficient code.

# Sample Code

THe sample code can be otained from:

 * [https://github.com/gavinb/cplusplus11/blob/master/final/](https://github.com/gavinb/cplusplus11/tree/master/final/)

# Final vs Override

In addition to the `final` modifier, there is support for expressing the
opposite sense; the `override` declaration makes it explicit to the compiler
that you are intentionally overriding a virtual method from a base class.
This is explained in its own article, [C++11 and
override](/2014/06/c-plus-plus-11-and-override.html).


----

## rename a MySQL database (change schema name)?

For InnoDB, the following seems to work: create the new empty database, then rename each table in turn into the new database:

RENAME TABLE old_db.table TO new_db.table;

You will need to adjust the permissions after that.

For scripting in a shell, you can use either of the following:

mysql -u username -ppassword old_db -sNe 'show tables' | while read table; \ 
    do mysql -u username -ppassword -sNe "rename table old_db.$table to new_db.$table"; done

OR

for table in `mysql -u root -ppassword -s -N -e "use old_db;show tables from old_db;"`; do mysql -u root -ppassword -s -N -e "use old_db;rename table old_db.$table to new_db.$table;"; done;

Notes:

    There is no space between the option -p and the password. If your database has no password, remove the -u username -ppassword part.

    If some table has a trigger, it cannot be moved to another database using above method (will result Trigger in wrong schema error). If that is the case, use a traditional way to clone a database and then drop the old one:

    mysqldump old_db | mysql new_db

    If you have stored procedures, you can copy them afterwards:

    mysqldump -R old_db | mysql new_db





se these few simple commands:

mysqldump -u username -p -v olddatabase > olddbdump.sql
mysqladmin -u username -p create newdatabase
mysql -u username -p newdatabase < olddbdump.sql

Or to reduce I/O use the following as suggested by @Pablo Marin-Garcia:

mysqladmin -u username -p create newdatabase
mysqldump -u username -v olddatabase -p | mysql -u username -p -D newdatabase



### Emulating the missing RENAME DATABASE command in MySQL:

    Create a new database

    Create the rename queries with:

     SELECT CONCAT('RENAME TABLE ',table_schema,'.`',table_name,
         '` TO ','new_schema.`',table_name,'`;')
     FROM information_schema.TABLES
     WHERE table_schema LIKE 'old_schema';

    Run that output

    Delete old database




### Please note that this will not work for views. You cannot rename views to make them jump from a database to another. Use DROP VIEW and CREATE VIEW instead. Clumsy, yes. You might want to do a mysqldump to move the views, after first moving all the tables. Also note that SHOW TABLES will show tables AND views, so beware.


### 


2010-02-17
Emulating The Missing RENAME DATABASE Command in MySQL
I'll approach this topic from another direction.
I had to perform a task which required moving tables between schemas on the same MySQL server.
One way of doing this would be:

    Dumping the original table to disk.
    Creating new empty table on the target schema.
    Importing table from disk into the target schema.

But, a simpler way exists!
The manual entry for RENAME TABLE casually describes this feature:

    As long as two databases are on the same file system, you can use RENAME TABLE to move a table from one database to another:

    RENAME TABLE current_db.tbl_name TO other_db.tbl_name;

Which works almost instantaneously and does what it is supposed to do. This command could also be called MOVE TABLE.

Using this command, it is easy to emulate the missing RENAME DATABASE command.

    Create the new schema.
    Perform a query to generate the move commands from the source to the target schema:

            SELECT CONCAT('RENAME TABLE ',table_schema,'.',table_name,
            ' TO ','new_schema.',table_name,';')
            FROM information_schema.TABLES
            WHERE table_schema LIKE 'old_schema';

    Run those by copying them from your editor, or whatnot. If you're using SQLyog, CTRL-L switches the results tab to text mode for easy copying.
    Drop the old schema

Some notes:
If you're using InnoDB foreign keys, worry not. The constraints are kept across databases, and moving the tables does not affect them - no need to move the tables in any specific order.
The move command also moves the .idb files between the database directories, if you're using innodb_file_per_table.

Hope this helps.
Email ThisBlogThis!Share to TwitterShare to FacebookShare to Pinterest
Labels: Databases, MySQL
7 comments:

    gtowey2/17/10, 11:59 AM

    Don't forget stored procedures, functions and triggers!

    Also, you might as well make it one atomic operation, instead of separate statements:

    SELECT CONCAT('RENAME TABLE ', GROUP_CONCAT( table_schema,'.',table_name, ' TO ','new_schema.',table_name,' '),';') as stmt FROM information_schema.TABLES WHERE table_schema LIKE 'old_schema' GROUP BY table_schema;
    Reply

----

myisam vs innodb


I hope it helped you. In the case it was one of those search dead ends and I wasted you a browser tab and a click... that's unfortunate.



## See Who's Connected to Your MySQL Server
I'm posting this here since it has been useful for me, and the blog is a nice place to keep public notes.
If you have servers which have multiple application servers connected to them, you often need to see things like who's connected, how many connections they have, and which users. Using SHOW PROCESSLIST doesn't work that well, since it gives you a row for each server.

What we want is an output similar to this:

    +-----------------+-----------------+----------+
    | host_short      | users           | count(*) |
    +-----------------+-----------------+----------+
    | slave1          | repl            |        1 |
    | slave2          | repl            |        1 |
    | localhost       | event_scheduler |        1 |
    | 111.111.222.111 | root, foo       |        2 |
    | 111.111.222.222 | appuser, bar    |        3 |
    | 111.111.222.333 | appuser, moshe  |        9 |
    +-----------------+-----------------+----------+

And it is achieved using a simple query such as this one:

SELECT SUBSTRING_INDEX(host, ':', 1) AS host_short,
       GROUP_CONCAT(DISTINCT USER)   AS users,
       COUNT(*)
FROM   information_schema.processlist
GROUP  BY host_short
ORDER  BY COUNT(*),
          host_short;




## Renaming Tables with InnoDB

If you’re using MySQL version 5.5 (or greater), you are likely using the InnoDB storage engine, which makes the task of renaming databases quite simple.

In short, you can use the RENAME TABLE command within a MySQL prompt to effectively change the database name of a particular table while keeping the table name intact. However, doing so requires that the database with the new name already exists, so begin by creating a new database using the mysqladmin shell command as seen above.

For example, if we already have a catalog database that we want to rename to library, we’d first create the new library database:

$ mysqladmin -u username -p"password" create library

Now connect to the mysql prompt and issue the following MySQL RENAME TABLE statement for a table of your choice:

mysql> RENAME TABLE catalog.books TO library.books;

We’ve just moved the entirety of the books table from the catalog database to our new library database. This command can be executed manually for all relevant tables as desired, or we can simplify the task with a shell script as seen below.



## 

InnoDB is a general-purpose storage engine that balances high reliability and high performance. In MySQL 8.0, InnoDB is the default MySQL storage engine. Unless you have configured a different default storage engine, issuing a CREATE TABLE statement without an ENGINE clause creates an InnoDB table.
Key Advantages of InnoDB

    Its DML operations follow the ACID model, with transactions featuring commit, rollback, and crash-recovery capabilities to protect user data. See Section 15.2, “InnoDB and the ACID Model”.

    Row-level locking and Oracle-style consistent reads increase multi-user concurrency and performance. See Section 15.7, “InnoDB Locking and Transaction Model”.

    InnoDB tables arrange your data on disk to optimize queries based on primary keys. Each InnoDB table has a primary key index called the clustered index that organizes the data to minimize I/O for primary key lookups. See Section 15.6.2.1, “Clustered and Secondary Indexes”.

    To maintain data integrity, InnoDB supports FOREIGN KEY constraints. With foreign keys, inserts, updates, and deletes are checked to ensure they do not result in inconsistencies across related tables. 


    mysql> SHOW ENGINES\G

## MySQL 8.0 Supported Storage Engines

    InnoDB: The default storage engine in MySQL 8.0. InnoDB is a transaction-safe (ACID compliant) storage engine for MySQL that has commit, rollback, and crash-recovery capabilities to protect user data. InnoDB row-level locking (without escalation to coarser granularity locks) and Oracle-style consistent nonlocking reads increase multi-user concurrency and performance. InnoDB stores user data in clustered indexes to reduce I/O for common queries based on primary keys. To maintain data integrity, InnoDB also supports FOREIGN KEY referential-integrity constraints. For more information about InnoDB, see Chapter 15, The InnoDB Storage Engine.

    MyISAM: These tables have a small footprint. Table-level locking limits the performance in read/write workloads, so it is often used in read-only or read-mostly workloads in Web and data warehousing configurations.

    Memory: Stores all data in RAM, for fast access in environments that require quick lookups of non-critical data. This engine was formerly known as the HEAP engine. Its use cases are decreasing; InnoDB with its buffer pool memory area provides a general-purpose and durable way to keep most or all data in memory, and NDBCLUSTER provides fast key-value lookups for huge distributed data sets.

    CSV: Its tables are really text files with comma-separated values. CSV tables let you import or dump data in CSV format, to exchange data with scripts and applications that read and write that same format. Because CSV tables are not indexed, you typically keep the data in InnoDB tables during normal operation, and only use CSV tables during the import or export stage. 



## vagrant

headless



```rb
...
config.vm.provider "virtualbox" do |v|
  ...
  # By default, VirtualBox machines are started in headless mode, meaning there is no UI for the machines visible on the host machine.
  # https://developer.hashicorp.com/vagrant/docs/providers/virtualbox/configuration
  vb.gui = true
  ...
end
...
```

to get a gui on a running headless machine if you can see it in the VirtualBox Manager:

    You can suspend the machine (Close|Save State or vagrant suspend) and then start it again. When you restart it, you will see the GUI.





 vagrant reload after enabling gui.

But there is a trick (a bit risky in my opinion) 1. save the state of the VM VBoxManage controlvm NAME_OR_UUID savestate 2. star vbox gui and resume

## NAT网络 vs NAT