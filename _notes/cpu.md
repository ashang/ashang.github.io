


intel和AMD哪家处理器更好？

这个问题换个说法：酷睿十一代约ZEN3打架，谁赢了？ （这样就把时间点限制在当下，未来哪家厉害，此文不作猜测）

注：ZEN3对应ryzen 5000系列，属锐龙四代。

第一场：制程之战

目前的制程数值，不能反应真实水平。

早期的半导体制程用栅极宽度来描述，但并不是强制性标准。台积电营销负责人曾说，从0.35微米（350nm）开始，所谓的工艺数字就不再真正代表物理尺度了，7nm仅是一种行业标准化术语而已。至于这个7nm、10nm、14nm到底是采用什么标准计算出来的，站长没查询到资料。只能说，各家的标准根本不一样。打个比喻：到市场买肉，有的标注20元/磅，有的是40元/公斤，20元的不一定便宜，因为衡量的标准不同。

英特尔建议以晶体管密度（MTr/mm2，每平方毫米的百万晶体管数）来作为定义工艺节点的指标，可惜的是，目前在具体产品的销售中并没有引用“晶体管密度”这一指标，仍然采用7nm、10nm等“术语”，仅从数字大小看就容易误判。

酷睿十一代（移动版）采用的是intel 10nm工艺，其晶体管密度为每平方毫米1.008亿个。

酷睿十一代（桌面版）采用的是intel 14nm工艺，晶体管密度0.4467亿个。

ZEN3采用的是台积电7nm工艺， 晶体管密度为每平方毫米0.965亿个。

由此可见，intel 10nm比台积电7nm还高一点点，基本上算个平手。 

 CPU制程

 第二场：核心效率之战

站长选取的研究样本如下：

酷睿一代：i7-920 

酷睿二代：i7-2600K

酷睿三代：i7-3770、i7-3770K

酷睿四代：i7-4770、i7-4770K

酷睿五代：i7-5775C

酷睿六代：i7-6700、i7-6700K

酷睿七代：i7-7700、i7-7700K

酷睿八代：i7-8700K

酷睿九代：i7-9700KF、i9-9900KF

酷睿十代：i5-10600KF、i7-10700KF

酷睿十一代桌面版：i5-11600KF、i7-11700K

酷睿十一代移动版：i7-11800H

挖掘机系列：A12-9800

锐龙一代（ZEN）：R5-1500X、R7-1800X

锐龙二代（ZEN+）：R5-2600X、R7-2700X

锐龙三代（ZEN2）：R5-3600X、R7-3700X

锐龙四代（ZEN3）：R5-5600X、R7-5800X

锐龙四代移动版（ZEN3）：R7-5800H、R9-5900HX

在具体计算上，IPC是没有一个确定值的，站长采用的办法是单核以CINEBENCH为主，多核以3DMARK FS和TS CPU成绩为主，通过一定的算法得到下图，这样的结果能符合大多数应用场景，也能和两家官方公布的各代提升比例基本吻合。

 酷睿和锐龙的核心效率天梯图

上图解读

如果把CPU看做金庸小说里的侠客，IPC就相当于内功。

在农机时代（2011年10月~2017年2月），AMD没有还手之力。

AMD于2011年10月推出了“推土机”处理器架构，后来又陆续发布打桩机、压路机和挖掘机架构，一直到2017年2月第一代ZEN发布的这一个时间段，俗称“农机时代”。 这一时期对AMD来说是悲伤的时光，内功十分可怜，连酷睿一代都打不过，遇到酷睿二代直接被打飞。

锐龙一代（ZEN架构）是个转折点， 一步登天超过酷睿五代，锐龙二代（ZEN+）距离当时竞争对手酷睿八代仅有一步之遥，接着在锐龙三代（ZEN2）实现了对英特尔的超越。

酷睿八、九、十代（注2）的核心效率没有提升

英特尔这边，第七代提升极小，第八九十代都是原地踏步，眼睁睁地看到AMD从后面超过去。

说到这，有些读者非常疑惑，不是都说第八代提升最大的吗？

这是两个概念，第八代是“提升了核心数量”，并不是我们这里讨论的“提升核心效率”，二者是完全不同的概念。核心效率是可以理解为在相同的核心数量、相同的线程数量、相同的频率这“三个相同”的基础上，对比谁更厉害。

第九代改进很小，配不上“跨代提升”这个词语。

第十代桌面版效率也没有提升。把第八代的i7做一番改动，就成为第十代的i5。例如：i5-10500可以看做是i7-8700小改而来，二者仅频率上有些细微差异。当然，十代的部分型号也加入了一些新技术，如睿频3.0，这和IPC没什么关系。

注2：第十代酷睿移动版有两种微架构，Comet Lake和Ice Lake，此图仅包含桌面版，移动版Comet Lake效率没变，移动版Ice Lake有提升但未纳入对比范围。





https://topic.expreview.com/CPU/




含桌面处理器、笔记本移动处理器、服务器处理器
排名 	处理器 	分数 	图例
1 	AMD Ryzen Threadripper PRO 3995WX 	88,675 	AMD
2 	AMD EPYC 7763 	87,686 	AMD
3 	AMD EPYC 7713 	86,512 	AMD
4 	AMD EPYC 7J13 	84,964 	AMD
5 	AMD EPYC 7643 	77,101 	AMD
6 	AMD EPYC 7662 	71,576 	AMD
7 	AMD EPYC 7702 	71,046 	AMD
8 	AMD Ryzen Threadripper PRO 3975WX 	65,123 	AMD
9 	AMD EPYC 7443P 	58,896 	AMD
10 	AMD EPYC 7R32 	58,556 	AMD
11 	AMD EPYC 7542 	56,310 	AMD
12 	AMD EPYC 7502 	53,591 	AMD
13 	AMD EPYC 7513 	53,504 	AMD
14 	AMD Ryzen Threadripper 3990X 	50,658 	AMD
15 	AMD Ryzen Threadripper 3970X 	47,956 	AMD
16 	AMD EPYC 7742 	47,281 	AMD
17 	AMD Ryzen Threadripper 3960X 	46,240 	AMD
18 	AMD EPYC 7702P 	46,067 	AMD
19 	AMD EPYC 7343 	45,882 	AMD
20 	AMD EPYC 7402 	45,684 	AMD
21 	AMD Ryzen 9 5950X 	45,564 	AMD
22 	AMD EPYC 7413 	43,037 	AMD
23 	AMD EPYC 7313P 	42,800 	AMD
24 	AMD Ryzen Threadripper PRO 3955WX 	42,152 	AMD
25 	AMD EPYC 7F52 	40,468 	AMD
26 	AMD Ryzen 9 5900X 	40,446 	AMD
27 	Intel Xeon Gold 6248R @ 3.00GHz 	38,521 	intel
28 	AMD EPYC 7452 	38,257 	AMD
29 	Intel Xeon Platinum 8280 @ 2.70GHz 	37,575 	intel
30 	AMD EPYC 7402P 	37,311 	AMD
31 	Intel Xeon Gold 6242R @ 3.10GHz 	34,987 	intel
32 	[8-Way] Intel Xeon E7-8880 v2 @ 2.50GHz 	34,923 	intel
33 	AMD Ryzen Threadripper PRO 3945WX 	34,884 	AMD
34 	Intel Xeon W-3275M @ 2.50GHz 	34,638 	intel
35 	Intel Xeon Platinum 8260M @ 2.30GHz 	34,340 	intel
36 	AMD EPYC 7302 	34,259 	AMD
37 	AMD Ryzen 9 3950X 	34,009 	AMD
38 	AMD Ryzen 9 5900 	33,986 	AMD
39 	AMD Ryzen 9 3900XT 	33,576 	AMD
40 	Intel Xeon W-3175X @ 3.10GHz 	33,538 	intel
41 	AMD EPYC 73F3 	33,124 	AMD
42 	AMD Ryzen 9 PRO 3900 	32,946 	AMD
43 	Intel Core i9-10980XE @ 3.00GHz 	32,521 	intel
44 	Intel Xeon Gold 6252 @ 2.10GHz 	32,410 	intel
45 	AMD Ryzen 9 3900X 	32,312 	AMD
46 	Intel Xeon Gold 6230R @ 2.10GHz 	32,113 	intel
47 	Intel Core i9-9990XE @ 4.00GHz 	31,941 	intel
48 	Intel Xeon Platinum 8168 @ 2.70GHz 	31,799 	intel
49 	Intel Xeon W-3265 @ 2.70GHz 	31,691 	intel
50 	Intel Xeon Platinum 8268 @ 2.90GHz 	31,689 	intel
51 	Intel Xeon Gold 6248 @ 2.50GHz 	31,285 	intel
52 	AMD EPYC 7302P 	31,213 	AMD
53 	AMD EPYC 7313 	31,182 	AMD
54 	AMD EPYC 7282 	30,915 	AMD
55 	AMD Ryzen 9 3900 	30,679 	AMD
56 	Intel Core i9-9960X @ 3.10GHz 	30,641 	intel
57 	Intel Xeon Platinum 8176 @ 2.10GHz 	30,583 	intel
58 	Intel Xeon Gold 5317 @ 3.00GHz 	30,555 	intel
59 	Intel Xeon Gold 6246R @ 3.40GHz 	30,485 	intel
60 	Intel Core i9-9980XE @ 3.00GHz 	30,367 	intel
61 	Intel Xeon W-3245 @ 3.20GHz 	30,300 	intel
62 	Intel Xeon Gold 6254 @ 3.10GHz 	30,018 	intel
63 	Intel Xeon Gold 6238 @ 2.10GHz 	28,870 	intel
64 	Intel Xeon Platinum 8173M @ 2.00GHz 	28,860 	intel
65 	Intel Xeon W-2191B @ 2.30GHz 	28,656 	intel
66 	Intel Xeon Gold 6210U @ 2.50GHz 	28,560 	intel
67 	Intel Xeon W-2275 @ 3.30GHz 	28,457 	intel
68 	Intel Core i9-9940X @ 3.30GHz 	28,121 	intel
69 	AMD Ryzen 7 5800X 	28,116 	AMD
70 	Intel Xeon Platinum 8175M @ 2.50GHz 	28,103 	intel
71 	Intel Core i9-11900K @ 3.50GHz 	28,082 	intel
72 	Intel Xeon Gold 6212U @ 2.40GHz 	28,060 	intel
73 	Intel Xeon Platinum 8259CL @ 2.50GHz 	27,896 	intel
74 	Intel Core i9-7980XE @ 2.60GHz 	27,815 	intel
75 	Intel Core i9-10940X @ 3.30GHz 	27,741 	intel
76 	Intel Xeon Gold 6154 @ 3.00GHz 	27,722 	intel
77 	Intel Core i7-11700K @ 3.60GHz 	27,108 	intel
78 	Intel Core i9-9920X @ 3.50GHz 	27,102 	intel
79 	Intel Xeon W-2295 @ 3.00GHz 	27,047 	intel
80 	Intel Xeon Platinum 8369HC @ 3.30GHz 	26,893 	intel
81 	Intel Xeon Gold 6226R @ 2.90GHz 	26,842 	intel
82 	Intel Xeon Gold 6208U @ 2.90GHz 	26,677 	intel
83 	Intel Xeon Gold 6148 @ 2.40GHz 	26,660 	intel
84 	Intel Xeon Platinum 8124M @ 3.00GHz 	26,652 	intel
85 	AMD EPYC 7272 	26,454 	AMD
86 	Intel Xeon Gold 6143 @ 2.80GHz 	26,128 	intel
87 	Intel Core i9-10920X @ 3.50GHz 	26,081 	intel
88 	AMD Ryzen Threadripper 2950X 	26,011 	AMD
89 	Intel Xeon W-3235 @ 3.30GHz 	25,759 	intel
90 	AMD Ryzen 7 PRO 3700 	25,748 	AMD
91 	Intel Xeon Gold 5220 @ 2.20GHz 	25,740 	intel
92 	Intel Xeon Gold 6246 @ 3.30GHz 	25,734 	intel
93 	Intel Core i9-7960X @ 2.80GHz 	25,730 	intel
94 	AMD Ryzen 7 PRO 5750G 	25,537 	AMD
95 	Intel Xeon W-2265 @ 3.50GHz 	25,531 	intel
96 	Intel Core i9-7940X @ 3.10GHz 	25,472 	intel
97 	Intel Xeon Gold 6138 @ 2.00GHz 	25,416 	intel
98 	Intel Xeon W-1370P @ 3.60GHz 	25,324 	intel
99 	Intel Xeon Gold 6242 @ 2.80GHz 	25,313 	intel
100 	Intel Core i7-11700KF @ 3.60GHz 	25,266 	intel
101 	Intel Xeon E5-2679 v4 @ 2.50GHz 	25,266 	intel
102 	Intel Xeon Silver 4310 @ 2.10GHz 	25,218 	intel
103 	Intel Xeon Gold 6146 @ 3.20GHz 	25,142 	intel
104 	Intel Xeon W-11955M @ 2.60GHz 	25,119 	intel
105 	Intel Core i9-11900KF @ 3.50GHz 	25,058 	intel
106 	Intel Xeon W-2195 @ 2.30GHz 	24,983 	intel
107 	Intel Core i9-11980HK @ 2.60GHz 	24,929 	intel
108 	Intel Core i9-11900F @ 2.50GHz 	24,835 	intel
109 	Intel Xeon Gold 6138T @ 2.00GHz 	24,800 	intel
110 	Intel Xeon W-2175 @ 2.50GHz 	24,751 	intel
111 	AMD Ryzen 7 3800X 	24,708 	AMD
112 	Intel Core i9-11900 @ 2.50GHz 	24,608 	intel
113 	Intel Xeon Gold 6230 @ 2.10GHz 	24,600 	intel
114 	Intel Xeon W-2170B @ 2.50GHz 	24,561 	intel
115 	11th Gen Intel Core i9-11900KB @ 3.30GHz 	24,523 	intel
116 	Intel Core i9-11900KB @ 3.30GHz 	24,523 	intel
117 	Intel Core i9-11950H @ 2.60GHz 	24,248 	intel
118 	Intel Xeon Platinum 8160 @ 2.10GHz 	24,241 	intel
119 	AMD Ryzen Threadripper 2990WX 	24,237 	AMD
120 	AMD Ryzen 9 5980HS 	24,069 	AMD
121 	Intel Xeon W-1290P @ 3.70GHz 	24,049 	intel
122 	AMD Ryzen 7 3800XT 	24,043 	AMD
123 	AMD Ryzen 9 5900HX 	24,039 	AMD
124 	Intel Core i9-10900K @ 3.70GHz 	24,008 	intel
125 	Intel Xeon Gold 6140 @ 2.30GHz 	23,964 	intel
126 	Intel Xeon Gold 6132 @ 2.60GHz 	23,907 	intel
127 	Intel Core i9-10850K @ 3.60GHz 	23,863 	intel
128 	Intel Core i9-10900KF @ 3.70GHz 	23,612 	intel
129 	Intel Core i7-11850H @ 2.50GHz 	23,609 	intel
130 	AMD Ryzen 7 3700X 	23,557 	AMD
131 	Intel Xeon Gold 6152 @ 2.10GHz 	23,498 	intel
132 	AMD EPYC 7502P 	23,465 	AMD
133 	Intel Core i7-11700 @ 2.50GHz 	23,456 	intel
134 	Intel Core i9-10900X @ 3.70GHz 	23,350 	intel
135 	Intel Xeon W-2255 @ 3.70GHz 	23,256 	intel
136 	Intel Core i9-7920X @ 2.90GHz 	23,248 	intel
137 	AMD Ryzen 9 5900HS 	23,226 	AMD
138 	Intel Core i9-9900X @ 3.50GHz 	23,214 	intel
139 	Intel Xeon E5-2699 v4 @ 2.20GHz 	23,200 	intel
140 	Intel Core i9-11900H @ 2.50GHz 	23,154 	intel
141 	Intel Core i9-10910 @ 3.60GHz 	22,948 	intel
142 	Intel Xeon E5-2699A v4 @ 2.40GHz 	22,948 	intel
143 	Intel Xeon Gold 5218R @ 2.10GHz 	22,849 	intel
144 	AMD Ryzen 5 5600X 	22,824 	AMD
145 	AMD Ryzen 7 5700G 	22,822 	AMD
146 	Intel Xeon Gold 5218 @ 2.30GHz 	22,576 	intel
147 	AMD Ryzen 7 5700GE 	22,566 	AMD
148 	Intel Xeon E5-2696 v3 @ 2.30GHz 	22,548 	intel
149 	Intel Core i9-9820X @ 3.30GHz 	22,508 	intel
150 	Intel Xeon E5-2699 v3 @ 2.30GHz 	22,375 	intel
151 	AMD Ryzen 7 PRO 5750GE 	22,354 	AMD
152 	AMD EPYC 7F32 	22,303 	AMD
153 	AMD EPYC 7371 	22,236 	AMD
154 	Intel Xeon W-1290E @ 3.50GHz 	22,138 	intel
155 	Intel Core i7-11800H @ 2.30GHz 	22,135 	intel
156 	AMD Ryzen 7 5800HS 	22,108 	AMD
157 	AMD Ryzen Threadripper 1950X 	22,054 	AMD
158 	Intel Core i9-9900KF @ 3.60GHz 	22,043 	intel
159 	Intel Core i9-7900X @ 3.30GHz 	21,972 	intel
160 	Intel Xeon W-1290 @ 3.20GHz 	21,882 	intel
161 	Intel Xeon E5-2697A v4 @ 2.60GHz 	21,875 	intel
162 	Intel Xeon E5-2698 v4 @ 2.20GHz 	21,836 	intel
163 	Intel Xeon Gold 6130T @ 2.10GHz 	21,803 	intel
164 	Intel Xeon W-2155 @ 3.30GHz 	21,790 	intel
165 	AMD Ryzen 7 4700G 	21,667 	AMD
166 	AMD Ryzen 7 5800 	21,612 	AMD
167 	Intel Core i9-11900T @ 1.50GHz 	21,553 	intel
168 	Intel Xeon E5-2697 v4 @ 2.30GHz 	21,525 	intel
169 	Intel Xeon W-2150B @ 3.00GHz 	21,522 	intel
170 	Intel Xeon E5-2673 v4 @ 2.30GHz 	21,474 	intel
171 	AMD Ryzen 7 5800H 	21,410 	AMD
172 	Intel Xeon E5-2697 v3 @ 2.60GHz 	21,365 	intel
173 	Intel Xeon E5-2690 v4 @ 2.60GHz 	21,326 	intel
174 	AMD EPYC 7281 	21,230 	AMD
175 	Intel Xeon E5-2698 v3 @ 2.30GHz 	21,133 	intel
176 	Intel Xeon E5-2696 v4 @ 2.20GHz 	21,077 	intel
177 	Intel Xeon E5-2682 v4 @ 2.50GHz 	21,066 	intel
178 	AMD Ryzen 5 PRO 5650G 	21,039 	AMD
179 	Intel Core i9-9900KS @ 4.00GHz 	21,035 	intel
180 	Intel Xeon Gold 6136 @ 3.00GHz 	21,018 	intel
181 	AMD Ryzen 7 PRO 4700G 	20,899 	AMD
182 	AMD EPYC 7571 	20,858 	AMD
183 	AMD Ryzen 5 PRO 3600 	20,850 	AMD
184 	AMD Ryzen 9 4900H 	20,716 	AMD
185 	AMD EPYC 7262 	20,691 	AMD
186 	AMD Ryzen 9 4900HS 	20,666 	AMD
187 	AMD Ryzen Threadripper 2920X 	20,660 	AMD
188 	AMD Ryzen 7 PRO 5850U 	20,659 	AMD
189 	AMD Ryzen 5 3600X 	20,561 	AMD
190 	AMD Ryzen 7 4700GE 	20,527 	AMD
191 	Intel Xeon Gold 6137 @ 3.90GHz 	20,443 	intel
192 	Intel Xeon E-2288G @ 3.70GHz 	20,271 	intel
193 	Intel Xeon E5-2695 v4 @ 2.10GHz 	20,258 	intel
194 	AMD Ryzen 7 PRO 4750GE 	20,163 	AMD
195 	Intel Core i9-9900K @ 3.60GHz 	20,155 	intel
196 	Intel Xeon W-11855M @ 3.20GHz 	20,088 	intel
197 	Intel Xeon E5-2695 v3 @ 2.30GHz 	20,081 	intel
198 	Intel Core i7-7900X @ 3.30GHz 	20,046 	intel
199 	AMD EPYC 7252 	19,965 	AMD
200 	Intel Core i7-6950X @ 3.00GHz 	19,960 	intel
201 	Intel Xeon E5-2687W v4 @ 3.00GHz 	19,933 	intel
202 	Intel Xeon E5-2689 v4 @ 3.10GHz 	19,892 	intel
203 	AMD Ryzen 7 5800U 	19,887 	AMD
204 	Intel Xeon E5-2680 v4 @ 2.40GHz 	19,886 	intel
205 	Intel Core i7-10700KF @ 3.80GHz 	19,857 	intel
206 	AMD Ryzen 5 5600G 	19,835 	AMD
207 	Intel Xeon E5-2686 v4 @ 2.30GHz 	19,801 	intel
208 	Intel Core i7-11700F @ 2.50GHz 	19,756 	intel
209 	Intel Xeon D-2187NT @ 2.00GHz 	19,741 	intel
210 	Intel Xeon Gold 6126 @ 2.60GHz 	19,711 	intel
211 	Intel Core i7-9800X @ 3.80GHz 	19,699 	intel
212 	Intel Xeon W-2245 @ 3.90GHz 	19,680 	intel
213 	Intel Xeon Gold 6144 @ 3.50GHz 	19,654 	intel
214 	AMD Ryzen 5 3600 	19,634 	AMD
215 	Intel Xeon E5-4669 v3 @ 2.10GHz 	19,615 	intel
216 	Intel Xeon W-2145 @ 3.70GHz 	19,601 	intel
217 	Intel Xeon W-1270 @ 3.40GHz 	19,536 	intel
218 	Intel Core i9-10900F @ 2.80GHz 	19,471 	intel
219 	Intel 0000 	19,359 	intel
220 	Intel Xeon E5-2690 v3 @ 2.60GHz 	19,295 	intel
221 	Intel Xeon E5-2686 v3 @ 2.00GHz 	19,255 	intel
222 	Intel Xeon W-1350 @ 3.30GHz 	19,154 	intel
223 	AMD Ryzen 5 PRO 5650GE 	19,144 	AMD
224 	Intel Core i5-11600K @ 3.90GHz 	19,067 	intel
225 	AMD Ryzen Threadripper 1920X 	19,065 	AMD
226 	Intel Xeon Gold 6130 @ 2.10GHz 	19,060 	intel
227 	Intel Xeon E5-2683 v4 @ 2.10GHz 	19,047 	intel
228 	AMD Ryzen 5 3600XT 	19,021 	AMD
229 	Intel Core i5-11600 @ 2.80GHz 	18,967 	intel
230 	AMD EPYC 7501 	18,942 	AMD
231 	Intel Xeon Silver 4214R @ 2.40GHz 	18,940 	intel
232 	Intel Core i9-9900 @ 3.10GHz 	18,847 	intel
233 	AMD Ryzen 5 5600GE 	18,791 	AMD
234 	Intel Core i7-10700 @ 2.90GHz 	18,784 	intel
235 	Intel Xeon E5-2676 v4 @ 2.40GHz 	18,763 	intel
236 	AMD Ryzen 7 4800HS 	18,741 	AMD
237 	Intel Xeon D-2183IT @ 2.20GHz 	18,627 	intel
238 	Intel Xeon E5-2680 v3 @ 2.50GHz 	18,615 	intel
239 	Intel Core i9-10900 @ 2.80GHz 	18,596 	intel
240 	AMD EPYC 7301 	18,564 	AMD
241 	AMD EPYC 7401P 	18,546 	AMD
242 	Intel Core i7-7820X @ 3.60GHz 	18,539 	intel
243 	Intel Xeon E5-2680R v4 @ 2.40GHz 	18,490 	intel
244 	AMD EPYC 7551 	18,483 	AMD
245 	Intel Xeon W-2140B @ 3.20GHz 	18,472 	intel
246 	Intel Xeon E5-2697R v4 @ 2.30GHz 	18,439 	intel
247 	Intel Xeon W-1290T @ 1.90GHz 	18,409 	intel
248 	AMD Ryzen 7 Extreme Edition 	18,378 	AMD
249 	AMD Ryzen Threadripper 2990X 	18,311 	AMD
250 	AMD Ryzen 5 5600H 	18,268 	AMD
251 	Intel Xeon E5-1681 v3 @ 2.90GHz 	18,238 	intel
252 	Intel Core i7-10700K @ 3.80GHz 	18,218 	intel
253 	11th Gen Intel Core i5-11400F @ 2.60GHz 	18,187 	intel
254 	Intel Core i5-11400F @ 2.60GHz 	18,187 	intel
255 	AMD Ryzen 7 4800U 	18,173 	AMD
256 	Intel Xeon Gold 5120T @ 2.20GHz 	18,145 	intel
257 	AMD EPYC 7351 	18,085 	AMD
258 	Intel Xeon Gold 6134 @ 3.20GHz 	18,083 	intel
259 	Intel Xeon W-1270P @ 3.80GHz 	18,079 	intel
260 	Intel Core i5-11600KF @ 3.90GHz 	18,078 	intel
261 	Intel Core i7-9700KF @ 3.60GHz 	18,061 	intel
262 	Intel Core i7-10700F @ 2.90GHz 	18,014 	intel
263 	Intel Core i5-11500 @ 2.70GHz 	17,899 	intel
264 	Intel Xeon W-10885M @ 2.40GHz 	17,895 	intel
265 	Intel Core i9-10900TE @ 1.80GHz 	17,888 	intel
266 	Intel Xeon Gold 6226 @ 2.70GHz 	17,850 	intel
267 	Intel Core i5-11400 @ 2.60GHz 	17,798 	intel
268 	AMD 4700S 	17,756 	AMD
269 	Intel Xeon Silver 4214 @ 2.20GHz 	17,722 	intel
270 	Intel Xeon E5-2687W v3 @ 3.10GHz 	17,720 	intel
271 	Intel Core i7-6900K @ 3.20GHz 	17,695 	intel
272 	AMD Ryzen 7 PRO 4750G 	17,693 	AMD
273 	Intel Xeon E5-2676 v3 @ 2.40GHz 	17,659 	intel
274 	[8-Way] Intel Xeon X7560 @ 2.27GHz 	17,658 	intel
275 	Intel Core i5-11500H @ 2.90GHz 	17,655 	intel
276 	Intel Xeon E-2286M @ 2.40GHz 	17,576 	intel
277 	Intel Core i9-10980HK @ 2.40GHz 	17,530 	intel
278 	AMD Ryzen Embedded V2718 	17,506 	AMD
279 	Intel Core i9-10885H @ 2.40GHz 	17,473 	intel
280 	Intel Xeon Silver 4216 @ 2.10GHz 	17,469 	intel
281 	Intel Xeon E5-2697 v2 @ 2.70GHz 	17,439 	intel
282 	Intel Xeon E5-2683 v3 @ 2.00GHz 	17,424 	intel
283 	Intel Core i7-9700K @ 3.60GHz 	17,354 	intel
284 	AMD Ryzen 7 PRO 2700X 	17,276 	AMD
285 	Intel Core i9-9980HK @ 2.40GHz 	17,252 	intel
286 	AMD Ryzen Threadripper 2970WX 	17,210 	AMD
287 	Intel Xeon E-2278GE @ 3.30GHz 	17,210 	intel
288 	AMD Ryzen 5 4600G 	17,197 	AMD
289 	Intel Xeon W-3223 @ 3.50GHz 	17,127 	intel
290 	Intel Core i9-10900T @ 1.90GHz 	17,102 	intel
291 	Intel Xeon E5-1680 v4 @ 3.40GHz 	17,093 	intel
292 	AMD Ryzen 5 PRO 4650G 	17,086 	AMD
293 	AMD Ryzen 5 3500X 	17,073 	AMD
294 	Intel Xeon E5-2673 v3 @ 2.40GHz 	17,071 	intel
295 	Intel Xeon E5-2660 v4 @ 2.00GHz 	17,069 	intel
296 	AMD Ryzen 7 2700X 	16,968 	AMD
297 	AMD Ryzen 5 PRO 5650U 	16,934 	AMD
298 	Intel Xeon E5-2678 v3 @ 2.50GHz 	16,905 	intel
299 	AMD Ryzen 5 PRO 4400G 	16,818 	AMD
300 	Intel Core i7-9700F @ 3.00GHz 	16,811 	intel
301 	Intel Xeon E-2286G @ 4.00GHz 	16,808 	intel
302 	Intel Core i7-8086K @ 4.00GHz 	16,806 	intel
303 	AMD EPYC 7551P 	16,789 	AMD
304 	Intel Xeon E5-2658 v4 @ 2.30GHz 	16,754 	intel
305 	Intel Core i7-10870H @ 2.20GHz 	16,719 	intel
306 	AMD Ryzen 5 PRO 4650GE 	16,682 	AMD
307 	Intel Xeon Gold 5117 @ 2.00GHz 	16,672 	intel
308 	Intel Xeon E-2246G @ 3.60GHz 	16,667 	intel
309 	Intel Xeon E5-1680 v3 @ 3.20GHz 	16,633 	intel
310 	Intel Xeon E5-2696 v2 @ 2.50GHz 	16,620 	intel
311 	Intel Xeon E5-2687W v2 @ 3.40GHz 	16,492 	intel
312 	Intel Xeon E5-2690 v2 @ 3.00GHz 	16,463 	intel
313 	Intel Xeon E5-2667 v4 @ 3.20GHz 	16,447 	intel
314 	Intel Xeon Gold 5118 @ 2.30GHz 	16,389 	intel
315 	AMD Ryzen 5 4600GE 	16,377 	AMD
316 	AMD EPYC 7232P 	16,365 	AMD
317 	Intel Xeon E5-1680 v2 @ 3.00GHz 	16,345 	intel
318 	Intel Core i7-10700TE @ 2.00GHz 	16,332 	intel
319 	Intel Xeon E5-2673 v2 @ 3.30GHz 	16,320 	intel
320 	Intel Xeon W-2135 @ 3.70GHz 	16,311 	intel
321 	Intel Xeon Gold 5120 @ 2.20GHz 	16,308 	intel
322 	Intel Xeon E5-2670 v3 @ 2.30GHz 	16,303 	intel
323 	Intel Xeon E5-2667 v2 @ 3.30GHz 	16,299 	intel
324 	Intel Xeon E5-2658 v3 @ 2.20GHz 	16,298 	intel
325 	AMD Ryzen 7 PRO 4750U 	16,294 	AMD
326 	Intel Xeon E5-1660 v4 @ 3.20GHz 	16,192 	intel
327 	AMD Ryzen Embedded V2748 	16,186 	AMD
328 	Intel Xeon E5-2660 v3 @ 2.60GHz 	16,184 	intel
329 	Intel Core i7-10750H @ 2.60GHz 	16,137 	intel
330 	Intel Xeon E5-2667 v3 @ 3.20GHz 	16,119 	intel
331 	Intel Core i7-9700 @ 3.00GHz 	16,111 	intel
332 	Intel Xeon E5-2669 v3 @ 2.30GHz 	16,107 	intel
333 	Intel Xeon E-2278G @ 3.40GHz 	16,082 	intel
334 	Intel Xeon Gold 5215 @ 2.50GHz 	16,058 	intel
335 	Intel Xeon E-2146G @ 3.50GHz 	16,050 	intel
336 	Intel Xeon E5-2692 v2 @ 2.20GHz 	16,018 	intel
337 	Intel Xeon Silver 4210 @ 2.20GHz 	15,974 	intel
338 	Intel Core i7-8700K @ 3.70GHz 	15,962 	intel
339 	Intel Core i7-5960X @ 3.00GHz 	15,946 	intel
340 	Intel Xeon D-2166NT @ 2.00GHz 	15,922 	intel
341 	Intel Xeon E5-2650 v4 @ 2.20GHz 	15,912 	intel
342 	AMD Ryzen 5 4600H 	15,900 	AMD
343 	AMD Ryzen 7 PRO 2700 	15,897 	AMD
344 	Intel Xeon E5-4657L v2 @ 2.40GHz 	15,896 	intel
345 	AMD Ryzen Threadripper 1900X 	15,881 	AMD
346 	Intel Xeon E5-2680 v2 @ 2.80GHz 	15,847 	intel
347 	Intel Xeon E5-2695 v2 @ 2.40GHz 	15,847 	intel
348 	AMD Ryzen 7 4800H 	15,832 	AMD
349 	AMD EPYC 7351P 	15,820 	AMD
350 	AMD EPYC 7451 	15,797 	AMD
351 	Intel Xeon E-2236 @ 3.40GHz 	15,781 	intel
352 	Intel Core i9-9900T @ 2.10GHz 	15,563 	intel
353 	Intel Xeon E5-4660 v3 @ 2.10GHz 	15,556 	intel
354 	Intel Xeon Platinum 8272CL @ 2.60GHz 	15,541 	intel
355 	Intel Xeon E5-4627 v4 @ 2.60GHz 	15,516 	intel
356 	Intel Xeon Silver 4215 @ 2.50GHz 	15,440 	intel
357 	Intel Xeon E-2186G @ 3.80GHz 	15,406 	intel
358 	AMD Ryzen 7 1800X 	15,394 	AMD
359 	Intel Core i5-10600KF @ 4.10GHz 	15,369 	intel
360 	AMD Ryzen 7 PRO 1700X 	15,349 	AMD
361 	Intel Xeon E-2136 @ 3.30GHz 	15,338 	intel
362 	Intel Xeon E5-2640 v4 @ 2.40GHz 	15,331 	intel
363 	Intel Xeon Silver 4116 @ 2.10GHz 	15,248 	intel
364 	Intel Xeon Silver 4214Y @ 2.20GHz 	15,248 	intel
365 	Intel Xeon Silver 4116T @ 2.10GHz 	15,187 	intel
366 	Intel Xeon Silver 4123 @ 3.00GHz 	15,185 	intel
367 	Intel Xeon E5-2675 v3 @ 1.80GHz 	15,156 	intel
368 	Intel Xeon Silver 4210R @ 2.40GHz 	15,145 	intel
369 	Intel Core i7-8700 @ 3.20GHz 	15,142 	intel
370 	Apple M1 8 Core 3200 MHz 	15,141 	via
371 	Intel Xeon W-1250 @ 3.30GHz 	15,077 	intel
372 	Intel Xeon Gold 5217 @ 3.00GHz 	15,036 	intel
373 	Intel Xeon Gold 6128 @ 3.40GHz 	15,022 	intel
374 	Intel Xeon E5-2685 v3 @ 2.60GHz 	15,004 	intel
375 	AMD Ryzen 7 2700 	15,001 	AMD
376 	Intel Xeon E5-2670 v2 @ 2.50GHz 	14,966 	intel
377 	Intel Core i5-10600K @ 4.10GHz 	14,947 	intel
378 	Intel Core i7-8700B @ 3.20GHz 	14,891 	intel
379 	Intel Core i7-9700T @ 2.00GHz 	14,859 	intel
380 	Intel Xeon E5-2650 v3 @ 2.30GHz 	14,841 	intel
381 	AMD Ryzen 5 PRO 4400GE 	14,795 	AMD
382 	Intel Xeon D-1567 @ 2.10GHz 	14,693 	intel
383 	Intel Xeon W-2235 @ 3.80GHz 	14,679 	intel
384 	AMD Ryzen 7 1700X 	14,677 	AMD
385 	Intel Xeon E5-2649 v3 @ 2.30GHz 	14,677 	intel
386 	AMD Ryzen 5 5600U 	14,668 	AMD
387 	AMD Ryzen 5 PRO 2600 	14,645 	AMD
388 	Intel Xeon W-1250P @ 4.10GHz 	14,632 	intel
389 	Intel Xeon E-2226G @ 3.40GHz 	14,627 	intel
390 	Intel Core i7-9750HF @ 2.60GHz 	14,598 	intel
391 	Intel Xeon E5-2618L v4 @ 2.20GHz 	14,592 	intel
392 	AMD Ryzen 5 4600U 	14,565 	AMD
393 	Intel Xeon E5-1660 v3 @ 3.00GHz 	14,565 	intel
394 	Intel Core i7-7800X @ 3.50GHz 	14,553 	intel
395 	Intel Core i9-8950HK @ 2.90GHz 	14,528 	intel
396 	Intel Core i5-11400H @ 2.70GHz 	14,524 	intel
397 	Intel Core i7-10710U @ 1.10GHz 	14,499 	intel
398 	Intel Xeon E-2186M @ 2.90GHz 	14,431 	intel
399 	Intel Xeon E-2176G @ 3.70GHz 	14,409 	intel
400 	Intel Xeon E5-2687W @ 3.10GHz 	14,381 	intel
401 	Intel Core i7-6850K @ 3.60GHz 	14,369 	intel
402 	Intel Core i7-10875H @ 2.30GHz 	14,353 	intel
403 	AMD Ryzen 5 2600X 	14,348 	AMD
404 	AMD Ryzen 7 4700U 	14,327 	AMD
405 	Intel Xeon Silver 4114 @ 2.20GHz 	14,252 	intel
406 	Intel Xeon E5-1650 v4 @ 3.60GHz 	14,231 	intel
407 	Intel Xeon E5-4627 v3 @ 2.60GHz 	14,221 	intel
408 	AMD Ryzen 7 PRO 1700 	14,171 	AMD
409 	AMD Ryzen 5 4600HS 	14,171 	AMD
410 	Intel Xeon E-2276G @ 3.80GHz 	14,143 	intel
411 	Intel Xeon E5-2658 v2 @ 2.40GHz 	14,128 	intel
412 	Intel Core i7-9750H @ 2.60GHz 	14,118 	intel
413 	Intel Xeon E5-2650L v4 @ 1.70GHz 	14,093 	intel
414 	Intel Xeon W-2133 @ 3.60GHz 	14,053 	intel
415 	Intel Xeon E-2126G @ 3.30GHz 	14,051 	intel
416 	AMD Ryzen 3 5300G 	13,995 	AMD
417 	Intel Xeon E5-2663 v3 @ 2.80GHz 	13,994 	intel
418 	AMD Ryzen 3 PRO 5350G 	13,982 	AMD
419 	Intel Xeon E5-2640 v3 @ 2.60GHz 	13,978 	intel
420 	Intel Xeon E-2276M @ 2.80GHz 	13,967 	intel
421 	Intel Xeon W-10855M @ 2.80GHz 	13,964 	intel
422 	Intel Xeon E-2176M @ 2.70GHz 	13,963 	intel
423 	Intel Xeon E5-4667 v3 @ 2.00GHz 	13,959 	intel
424 	Intel Xeon D-1587 @ 1.70GHz 	13,950 	intel
425 	Intel Core i5-9600KF @ 3.70GHz 	13,921 	intel
426 	Intel Xeon E-2278GEL @ 2.00GHz 	13,914 	intel
427 	Intel Xeon E5-2630 v4 @ 2.20GHz 	13,884 	intel
428 	Intel Core i7-9850H @ 2.60GHz 	13,866 	intel
429 	AMD Ryzen 3 5300GE 	13,843 	AMD
430 	Intel Xeon D-2143IT @ 2.20GHz 	13,816 	intel
431 	Intel Xeon E5-2643 v3 @ 3.40GHz 	13,801 	intel
432 	Intel Core i7-4960X @ 3.60GHz 	13,795 	intel
433 	Intel Xeon E5-1660 v2 @ 3.70GHz 	13,779 	intel
434 	AMD Ryzen 7 1700 	13,745 	AMD
435 	Intel Core i7-10700T @ 2.00GHz 	13,734 	intel
436 	Intel Xeon E5-2690 @ 2.90GHz 	13,722 	intel
437 	AMD Ryzen 3 PRO 5350GE 	13,672 	AMD
438 	Intel Xeon E5-2648L v4 @ 1.80GHz 	13,654 	intel
439 	Intel Core i7-5930K @ 3.50GHz 	13,631 	intel
440 	Intel Xeon E5-4669 v4 @ 2.20GHz 	13,626 	intel
441 	Intel Xeon E5-2643 v4 @ 3.40GHz 	13,618 	intel
442 	Intel Xeon E5-1650 v3 @ 3.50GHz 	13,612 	intel
443 	Intel Core i7-6800K @ 3.40GHz 	13,593 	intel
444 	AMD Ryzen 5 2600 	13,526 	AMD
445 	Intel Core i7-9700E @ 2.60GHz 	13,517 	intel
446 	Intel Xeon E5-2650L v3 @ 1.80GHz 	13,513 	intel
447 	Intel Core i5-9600 @ 3.10GHz 	13,498 	intel
448 	Intel Core i5-9600K @ 3.70GHz 	13,489 	intel
449 	Intel Xeon E5-2660 v2 @ 2.20GHz 	13,449 	intel
450 	Intel Xeon E5-2689 @ 2.60GHz 	13,427 	intel
451 	AMD Ryzen 3 3300X 	13,425 	AMD
452 	AMD Ryzen 5 PRO 4650U 	13,418 	AMD
453 	AMD Ryzen 7 2700E 	13,410 	AMD
454 	Intel Core i7-1165G7 @ 2.80GHz 	13,372 	intel
455 	Intel Core i5-11400T @ 1.30GHz 	13,367 	intel
456 	Intel Core i7-11370H @ 3.30GHz 	13,318 	intel
457 	Intel Core i7-11375H @ 3.30GHz 	13,285 	intel
458 	Intel Xeon E5-2628L v4 @ 1.90GHz 	13,268 	intel
459 	AMD Ryzen 5 1600X 	13,231 	AMD
460 	Intel Core i7-8850H @ 2.60GHz 	13,222 	intel
461 	Intel Core i5-10505 @ 3.20GHz 	13,147 	intel
462 	Intel Core i5-10400F @ 2.90GHz 	13,120 	intel
463 	Intel Xeon Silver 4208 @ 2.10GHz 	13,116 	intel
464 	Intel Core i5-10500H @ 2.50GHz 	13,115 	intel
465 	Intel Xeon E5-2650 v2 @ 2.60GHz 	13,104 	intel
466 	AMD Ryzen 5 3500 	13,064 	AMD
467 	Intel Core i7-4930K @ 3.40GHz 	13,014 	intel
468 	Intel Core i7-5820K @ 3.30GHz 	12,989 	intel
469 	Intel Core i5-9500F @ 3.00GHz 	12,956 	intel
470 	Intel Core i5-10400 @ 2.90GHz 	12,871 	intel
471 	AMD Ryzen 5 5500U 	12,866 	AMD
472 	Intel Xeon E5-2630L v4 @ 1.80GHz 	12,847 	intel
473 	Intel Xeon E5-2470 v2 @ 2.40GHz 	12,836 	intel
474 	Intel Xeon D-2141I @ 2.20GHz 	12,836 	intel
475 	Intel Xeon E5-2643 v2 @ 3.50GHz 	12,824 	intel
476 	Intel Xeon E5-2630 v3 @ 2.40GHz 	12,797 	intel
477 	Intel Core i5-8600K @ 3.60GHz 	12,783 	intel
478 	Intel Xeon E-2244G @ 3.80GHz 	12,782 	intel
479 	Intel Core i5-9400F @ 2.90GHz 	12,743 	intel
480 	Intel Xeon E5-1650 v2 @ 3.50GHz 	12,727 	intel
481 	Intel Xeon E5-4640 v3 @ 1.90GHz 	12,703 	intel
482 	Intel Core i7-9700TE @ 1.80GHz 	12,688 	intel
483 	Intel Core i5-9500 @ 3.00GHz 	12,673 	intel
484 	Intel Core i7-3970X @ 3.50GHz 	12,671 	intel
485 	Intel Core i5-8500B @ 3.00GHz 	12,639 	intel
486 	Intel Xeon E5-2680 @ 2.70GHz 	12,638 	intel
487 	Intel Core i5-8600 @ 3.10GHz 	12,627 	intel
488 	Intel Core i7-3960X @ 3.30GHz 	12,609 	intel
489 	Intel Xeon E-2274G @ 4.00GHz 	12,595 	intel
490 	Intel Core i5-10600 @ 3.30GHz 	12,560 	intel
491 	Intel Core i7-8700T @ 2.40GHz 	12,514 	intel
492 	Intel Core i7-8750H @ 2.20GHz 	12,461 	intel
493 	Intel Core i5-10500 @ 3.10GHz 	12,402 	intel
494 	AMD Ryzen 3 5400U 	12,367 	AMD
495 	Intel Xeon E5-1660 @ 3.30GHz 	12,364 	intel
496 	Intel Xeon W-2125 @ 4.00GHz 	12,362 	intel
497 	Intel Xeon E5-4655 v3 @ 2.90GHz 	12,292 	intel
498 	AMD Ryzen 5 1600 	12,264 	AMD
499 	Intel Core i7-7740X @ 4.30GHz 	12,255 	intel
500 	Intel Xeon Gold 6278C @ 2.60GHz 	12,242 	intel
501 	AMD Ryzen 5 PRO 1600 	12,213 	AMD
502 	Intel Xeon E5-2618L v3 @ 2.30GHz 	12,186 	intel
503 	AMD Ryzen 3 3100 	12,157 	AMD
504 	Intel Xeon E5-2670 @ 2.60GHz 	12,137 	intel
505 	Intel Xeon E5-4650 @ 2.70GHz 	12,117 	intel
506 	Intel Xeon E-2174G @ 3.80GHz 	12,108 	intel
507 	Intel Core i7-8559U @ 2.70GHz 	12,094 	intel
508 	AMD Ryzen 5 PRO 4500U 	12,049 	AMD
509 	AMD Ryzen 3 PRO 5450U 	12,047 	AMD
510 	Intel Core i7-7700K @ 4.20GHz 	12,039 	intel
511 	Intel Xeon Silver 4110 @ 2.10GHz 	12,025 	intel
512 	Intel Core i7-3930K @ 3.20GHz 	11,988 	intel
513 	Intel Xeon E5-2628L v3 @ 2.00GHz 	11,965 	intel
514 	Intel Xeon E3-1285 v6 @ 4.10GHz 	11,955 	intel
515 	Intel Core i5-8500 @ 3.00GHz 	11,916 	intel
516 	AMD EPYC 3251 	11,882 	AMD
517 	AMD Ryzen 3 4300GE 	11,878 	AMD
518 	Intel Xeon E5-4627 v2 @ 3.30GHz 	11,872 	intel
519 	Intel Xeon E5-4650L @ 2.60GHz 	11,821 	intel
520 	Intel Core i9-10880H @ 2.30GHz 	11,814 	intel
521 	AMD EPYC 7251 	11,811 	AMD
522 	Intel Xeon E5-1650 @ 3.20GHz 	11,745 	intel
523 	AMD Ryzen 3 4300G 	11,714 	AMD
524 	Intel Core i5-11300H @ 3.10GHz 	11,710 	intel
525 	Intel Core i5-9600T @ 2.30GHz 	11,706 	intel
526 	Intel Core i5-8400 @ 2.80GHz 	11,662 	intel
527 	Intel Core i5-9400 @ 2.90GHz 	11,656 	intel
528 	Intel Core i5-1145G7 @ 2.60GHz 	11,646 	intel
529 	Intel Core i7-1185G7E @ 2.80GHz 	11,645 	intel
530 	Intel Xeon D-1577 @ 1.30GHz 	11,645 	intel
531 	Intel Xeon E5-2665 @ 2.40GHz 	11,599 	intel
532 	Intel Core i5-1145G7E @ 2.60GHz 	11,488 	intel
533 	AMD Ryzen 3 PRO 4350G 	11,446 	AMD
534 	AMD Ryzen 3 PRO 4350GE 	11,417 	AMD
535 	Intel Xeon E5-2648L v3 @ 1.80GHz 	11,392 	intel
536 	Intel Xeon E5-2648L v2 @ 1.90GHz 	11,381 	intel
537 	AMD Ryzen 5 4500U 	11,372 	AMD
538 	Intel Xeon E3-1280 v6 @ 3.90GHz 	11,371 	intel
539 	Intel Core i5-9400H @ 2.50GHz 	11,370 	intel
540 	Intel Xeon E5-2620 v4 @ 2.10GHz 	11,364 	intel
541 	Intel Core i5-1035G7 @ 1.20GHz 	11,357 	intel
542 	AMD EPYC 7251 8-Core 	11,344 	AMD
543 	Intel Core i7-9850HL @ 1.90GHz 	11,340 	intel
544 	Intel Core i5-10600T @ 2.40GHz 	11,330 	intel
545 	Intel Xeon @ 2.00GHz 	11,327 	intel
546 	Intel Core i7-1160G7 @ 1.20GHz 	11,317 	intel
547 	AMD Ryzen 3 PRO 4200G 	11,315 	AMD
548 	Intel Core i5-10400T @ 2.00GHz 	11,312 	intel
549 	Intel Xeon E5-2651 v2 @ 1.80GHz 	11,275 	intel
550 	Intel Core i5-9500T @ 2.20GHz 	11,211 	intel
551 	Intel Core i7-4790K @ 4.00GHz 	11,181 	intel
552 	Intel Xeon E3-1270 v6 @ 3.80GHz 	11,135 	intel
553 	Intel Core i5-1035G4 @ 1.10GHz 	11,131 	intel
554 	Intel Xeon E3-1275 v6 @ 3.80GHz 	11,113 	intel
555 	Intel Core i7-6700K @ 4.00GHz 	11,111 	intel
556 	Intel Xeon Gold 5122 @ 3.60GHz 	11,104 	intel
557 	Intel Xeon E5-2660 @ 2.20GHz 	11,098 	intel
558 	Intel Xeon E5-4648 v3 @ 1.70GHz 	11,097 	intel
559 	Intel Core i7-8809G @ 3.10GHz 	11,072 	intel
560 	Intel Xeon D-1541 @ 2.10GHz 	11,056 	intel
561 	Intel Xeon E3-1285L v4 @ 3.40GHz 	11,048 	intel
562 	Intel Xeon E5-2629 v3 @ 2.40GHz 	11,022 	intel
563 	AMD Ryzen 3 PRO 4200GE 	11,006 	AMD
564 	Intel Core i7-5775C @ 3.30GHz 	10,992 	intel
565 	Intel Core i7-10850H @ 2.70GHz 	10,971 	intel
566 	Intel Xeon D-2146NT @ 2.30GHz 	10,968 	intel
567 	Intel Core i5-8259U @ 2.30GHz 	10,951 	intel
568 	Intel Xeon D-1557 @ 1.50GHz 	10,950 	intel
569 	Apple A12X Bionic 	10,940 	via
570 	Intel Core i7-1065G7 @ 1.30GHz 	10,932 	intel
571 	Intel Core i7-5950HQ @ 2.90GHz 	10,932 	intel
572 	Intel Core i5-8600T @ 2.30GHz 	10,913 	intel
573 	Intel Core i7-5775R @ 3.30GHz 	10,863 	intel
574 	Intel Xeon Silver 4109T @ 2.00GHz 	10,854 	intel
575 	Intel Xeon E5-4650 v3 @ 2.10GHz 	10,838 	intel
576 	Intel Core i5-1140G7 @ 1.10GHz 	10,821 	intel
577 	Intel Xeon Silver 4108 @ 1.80GHz 	10,769 	intel
578 	Intel Xeon E3-1575M v5 @ 3.00GHz 	10,755 	intel
579 	AMD Opteron 6386 SE 	10,748 	AMD
580 	Intel Core i7-7700 @ 3.60GHz 	10,748 	intel
581 	Intel Xeon E3-1585 v5 @ 3.50GHz 	10,743 	intel
582 	Intel Core i5-8257U @ 1.40GHz 	10,742 	intel
583 	Intel Xeon W-2123 @ 3.60GHz 	10,726 	intel
584 	Intel Xeon E3-1270L v4 @ 3.00GHz 	10,697 	intel
585 	Intel Xeon E3-1585L v5 @ 3.00GHz 	10,689 	intel
586 	Intel Xeon E5-4620 v3 @ 2.00GHz 	10,681 	intel
587 	Intel Xeon D-1548 @ 2.00GHz 	10,679 	intel
588 	Intel Xeon E3-1280 v5 @ 3.70GHz 	10,666 	intel
589 	AMD Ryzen 3 5300U 	10,642 	AMD
590 	Intel Xeon E3-1285 v4 @ 3.50GHz 	10,641 	intel
591 	Intel Core i5-8279U @ 2.40GHz 	10,623 	intel
592 	AMD Ryzen 5 PRO 3400G 	10,612 	AMD
593 	Intel Core i5-9400T @ 1.80GHz 	10,606 	intel
594 	Intel Xeon E3-1535M v6 @ 3.10GHz 	10,585 	intel
595 	Intel Xeon D-1540 @ 2.00GHz 	10,573 	intel
596 	Intel Core i5-1135G7 @ 2.40GHz 	10,537 	intel
597 	Intel Xeon E3-1245 v6 @ 3.70GHz 	10,535 	intel
598 	Intel Xeon E-2224 @ 3.40GHz 	10,525 	intel
599 	Intel Xeon E5-4640 @ 2.40GHz 	10,523 	intel
600 	Intel Core i5-8400H @ 2.50GHz 	10,516 	intel
601 	Intel Core i5-10500T @ 2.30GHz 	10,512 	intel
602 	Intel Core i7-8706G @ 3.10GHz 	10,510 	intel
603 	Intel Core i7-8557U @ 1.70GHz 	10,470 	intel
604 	Intel Xeon E5-2637 v4 @ 3.50GHz 	10,468 	intel
605 	Intel Core i3-9350KF @ 4.00GHz 	10,458 	intel
606 	Intel Xeon E3-1545M v5 @ 2.90GHz 	10,451 	intel
607 	Intel Xeon E3-1240 v5 @ 3.50GHz 	10,400 	intel
608 	Intel Core i7-1068NG7 @ 2.30GHz 	10,397 	intel
609 	Intel Xeon E5-2630 v2 @ 2.60GHz 	10,385 	intel
610 	Intel Xeon E-2144G @ 3.60GHz 	10,375 	intel
611 	Intel Xeon E5-2667 @ 2.90GHz 	10,367 	intel
612 	Intel Xeon E3-1285 v3 @ 3.60GHz 	10,359 	intel
613 	Intel Core i3-1125G4 @ 2.00GHz 	10,358 	intel
614 	Intel Xeon E3-1275 v5 @ 3.60GHz 	10,357 	intel
615 	Intel Xeon E3-1281 v3 @ 3.70GHz 	10,349 	intel
616 	Intel Xeon E3-1270 v5 @ 3.60GHz 	10,334 	intel
617 	Intel Xeon E-2134 @ 3.50GHz 	10,310 	intel
618 	AMD Ryzen 5 3400G 	10,309 	AMD
619 	Intel Xeon E5-1630 v4 @ 3.70GHz 	10,302 	intel
620 	AMD Ryzen 5 PRO 3400GE 	10,300 	AMD
621 	Intel Xeon E5-1630 v3 @ 3.70GHz 	10,277 	intel
622 	Intel Core i5-1130G7 @ 1.10GHz 	10,274 	intel
623 	Intel Core i7-4980HQ @ 2.80GHz 	10,253 	intel
624 	ARM Neoverse-N1 16 Core 0 MHz 	10,231 	via
625 	Intel Core i3-10320 @ 3.80GHz 	10,196 	intel
626 	AMD FX-9590 Eight-Core 	10,192 	AMD
627 	Intel Xeon E5-2450 @ 2.10GHz 	10,186 	intel
628 	Intel Xeon E3-1245 v5 @ 3.50GHz 	10,181 	intel
629 	Intel Xeon E3-1276 v3 @ 3.60GHz 	10,170 	intel
630 	Intel Xeon E3-1240 v6 @ 3.70GHz 	10,148 	intel
631 	Intel Core i3-9320 @ 3.70GHz 	10,144 	intel
632 	Intel Xeon E5-2637 v3 @ 3.50GHz 	10,144 	intel
633 	Intel Xeon E5-2650 @ 2.00GHz 	10,129 	intel
634 	AMD Ryzen 5 PRO 1500 	10,118 	AMD
635 	Intel Xeon E3-1515M v5 @ 2.80GHz 	10,093 	intel
636 	Intel Xeon E3-1271 v3 @ 3.60GHz 	10,092 	intel
637 	Intel Core i7-4770K @ 3.50GHz 	10,091 	intel
638 	Intel Core i7-8705G @ 3.10GHz 	10,090 	intel
639 	Intel Xeon E3-1260L v5 @ 2.90GHz 	10,083 	intel
640 	AMD Ryzen 5 1500X 	10,081 	AMD
641 	AMD Opteron 6380 	10,081 	AMD
642 	Intel Core i7-7920HQ @ 3.10GHz 	10,067 	intel
643 	Intel Xeon E5-2470 @ 2.30GHz 	10,061 	intel
644 	Intel Xeon E-2124G @ 3.40GHz 	10,048 	intel
645 	AMD Ryzen 5 PRO 2400G 	10,046 	AMD
646 	Intel Core i7-7820HK @ 2.90GHz 	10,042 	intel
647 	Intel Core i5-8500T @ 2.10GHz 	10,028 	intel
648 	Intel Xeon E5-2620 v3 @ 2.40GHz 	10,020 	intel
649 	Intel Core i3-9300 @ 3.70GHz 	10,018 	intel
650 	Intel Xeon E3-1241 v3 @ 3.50GHz 	10,014 	intel
651 	Intel Xeon E-2224G @ 3.50GHz 	10,008 	intel
652 	Intel Core i7-6700 @ 3.40GHz 	10,008 	intel
653 	Intel Xeon E5-2640 v2 @ 2.00GHz 	9,993 	intel
654 	Intel Core i7-4790 @ 3.60GHz 	9,990 	intel
655 	Intel Xeon W-2225 @ 4.10GHz 	9,982 	intel
656 	Intel Xeon E3-1285L v3 @ 3.10GHz 	9,981 	intel
657 	Intel Xeon E5-1620 v4 @ 3.50GHz 	9,954 	intel
658 	Intel Core i7-4940MX @ 3.10GHz 	9,905 	intel
659 	Intel Xeon E3-1275 v3 @ 3.50GHz 	9,901 	intel
660 	Intel Xeon E3-1286 v3 @ 3.70GHz 	9,899 	intel
661 	Intel Xeon E3-1270 v3 @ 3.50GHz 	9,898 	intel
662 	Intel Core i7-4771 @ 3.50GHz 	9,873 	intel
663 	Intel Xeon E3-1505M v6 @ 3.00GHz 	9,865 	intel
664 	Intel Xeon E3-1246 v3 @ 3.50GHz 	9,855 	intel
665 	Intel Core i5-1038NG7 @ 2.00GHz 	9,823 	intel
666 	Intel Core i7-4770R @ 3.20GHz 	9,819 	intel
667 	Intel Core i7-5850EQ @ 2.70GHz 	9,817 	intel
668 	Intel Core i7-995X @ 3.60GHz 	9,791 	intel
669 	AMD Opteron 6287 SE 	9,789 	AMD
670 	Intel Core i7-4770 @ 3.40GHz 	9,786 	intel
671 	Intel Xeon E3-1230 v5 @ 3.40GHz 	9,778 	intel
672 	Intel Core i7-4960HQ @ 2.60GHz 	9,777 	intel
673 	Intel Xeon E5-2650L v2 @ 1.70GHz 	9,777 	intel
674 	Intel Xeon E5-1620 v3 @ 3.50GHz 	9,758 	intel
675 	Intel Core i7-8569U @ 2.80GHz 	9,754 	intel
676 	Intel Xeon E3-1280 v3 @ 3.60GHz 	9,747 	intel
677 	Intel Xeon D-1531 @ 2.20GHz 	9,730 	intel
678 	Intel Core i7-8665U @ 1.90GHz 	9,730 	intel
679 	Intel Core i7-4820K @ 3.70GHz 	9,721 	intel
680 	Intel Core i7-6770HQ @ 2.60GHz 	9,719 	intel
681 	Intel Xeon E3-1290 V2 @ 3.70GHz 	9,709 	intel
682 	Intel Core i3-10305 @ 3.80GHz 	9,689 	intel
683 	AMD Ryzen 5 3350GE 	9,684 	AMD
684 	Intel Xeon E-2276ME @ 2.80GHz 	9,680 	intel
685 	AMD Ryzen 3 PRO 4450U 	9,670 	AMD
686 	AMD Ryzen 5 2500X 	9,670 	AMD
687 	Intel Xeon E3-1240 v3 @ 3.40GHz 	9,663 	intel
688 	Intel Core i5-8400T @ 1.70GHz 	9,659 	intel
689 	Intel Xeon E3-1230 v6 @ 3.50GHz 	9,644 	intel
690 	AMD Ryzen 5 PRO 3350GE 	9,643 	AMD
691 	AMD EPYC 3201 	9,634 	AMD
692 	Intel Xeon E3-1231 v3 @ 3.40GHz 	9,631 	intel
693 	Intel Core i7-6920HQ @ 2.90GHz 	9,620 	intel
694 	Intel Core i5-7640X @ 4.00GHz 	9,605 	intel
695 	AMD Ryzen 5 PRO 3350G 	9,581 	AMD
696 	Intel Xeon E3-1245 v3 @ 3.40GHz 	9,579 	intel
697 	Intel Core i7-4790S @ 3.20GHz 	9,572 	intel
698 	AMD Ryzen 7 5700U 	9,572 	AMD
699 	Intel Xeon E5-4610 @ 2.40GHz 	9,552 	intel
700 	Intel Core i7-8709G @ 3.10GHz 	9,536 	intel
701 	Intel Core i7-3770K @ 3.50GHz 	9,518 	intel
702 	Intel Xeon E5-2640 @ 2.50GHz 	9,512 	intel
703 	Intel Core i5-9300H @ 2.40GHz 	9,504 	intel
704 	Intel Core i5-10300H @ 2.50GHz 	9,501 	intel
705 	Intel Xeon E3-1286L v3 @ 3.20GHz 	9,495 	intel
706 	Intel Core i7-4930MX @ 3.00GHz 	9,485 	intel
707 	Intel Xeon E5-2658 @ 2.10GHz 	9,484 	intel
708 	Intel Xeon E5-2630L v3 @ 1.80GHz 	9,476 	intel
709 	Intel Xeon E3-1270 V2 @ 3.50GHz 	9,473 	intel
710 	Intel Xeon E3-1280 V2 @ 3.60GHz 	9,470 	intel
711 	AMD FX-9370 Eight-Core 	9,465 	AMD
712 	Intel Core i7-5850HQ @ 2.70GHz 	9,459 	intel
713 	Intel Xeon E5-1620 v2 @ 3.70GHz 	9,458 	intel
714 	Intel Xeon E-2254ML @ 1.70GHz 	9,458 	intel
715 	Intel Core i5-8300H @ 2.30GHz 	9,450 	intel
716 	Intel Xeon E-2234 @ 3.60GHz 	9,450 	intel
717 	Intel Xeon E3-1275 V2 @ 3.50GHz 	9,445 	intel
718 	Intel Xeon E5-2637 v2 @ 3.50GHz 	9,431 	intel
719 	Intel Xeon Gold 5222 @ 3.80GHz 	9,428 	intel
720 	Intel Xeon E5-2440 v2 @ 1.90GHz 	9,425 	intel
721 	AMD Opteron 6376 	9,414 	AMD
722 	Intel Core i7-10510U @ 1.80GHz 	9,412 	intel
723 	Intel Xeon E5-2628L v2 @ 1.90GHz 	9,405 	intel
724 	Intel Core i7-4910MQ @ 2.90GHz 	9,400 	intel
725 	Intel Core i3-10300 @ 3.70GHz 	9,381 	intel
726 	AMD Ryzen 5 PRO 2400GE 	9,376 	AMD
727 	AMD Opteron 6344 	9,372 	AMD
728 	Intel Core i7-4870HQ @ 2.50GHz 	9,362 	intel
729 	Intel Xeon E-2124 @ 3.30GHz 	9,354 	intel
730 	Intel Core i7-4770S @ 3.10GHz 	9,336 	intel
731 	Intel Core i7-7820HQ @ 2.90GHz 	9,335 	intel
732 	Intel Core i3-10100F @ 3.60GHz 	9,323 	intel
733 	Intel Xeon E3-1230 v3 @ 3.30GHz 	9,321 	intel
734 	Intel Xeon E3-1535M v5 @ 2.90GHz 	9,319 	intel
735 	AMD Ryzen 7 3750H 	9,311 	AMD
736 	Intel Core i7-3940XM @ 3.00GHz 	9,309 	intel
737 	AMD Ryzen 5 2400G 	9,290 	AMD
738 	Intel Core i7-3770 @ 3.40GHz 	9,289 	intel
739 	Intel Xeon E5-2630L v2 @ 2.40GHz 	9,283 	intel
740 	Intel Core i7-4860HQ @ 2.40GHz 	9,265 	intel
741 	Intel Core i5-10200H @ 2.40GHz 	9,259 	intel
742 	Intel Core i3-8350K @ 4.00GHz 	9,245 	intel
743 	Intel Xeon E5-4607 v2 @ 2.60GHz 	9,234 	intel
744 	Intel Xeon E3-1265L v3 @ 2.50GHz 	9,223 	intel
745 	Intel Core i5-9500TE @ 2.20GHz 	9,212 	intel
746 	Intel Core i7-7700T @ 2.90GHz 	9,189 	intel
747 	Intel Xeon E5-2440 @ 2.40GHz 	9,178 	intel
748 	Intel Xeon W3690 @ 3.47GHz 	9,160 	intel
749 	Intel Core i3-9100 @ 3.60GHz 	9,158 	intel
750 	Intel Core i7-8565U @ 1.80GHz 	9,154 	intel
751 	Intel Core i5-8305G @ 2.80GHz 	9,152 	intel
752 	AMD Opteron 6348 	9,151 	AMD
753 	Intel Core i7-3920XM @ 2.90GHz 	9,149 	intel
754 	AMD Ryzen 7 PRO 3700U 	9,146 	AMD
755 	Intel Core i7-7820EQ @ 3.00GHz 	9,144 	intel
756 	Intel Xeon E3-1240 V2 @ 3.40GHz 	9,138 	intel
757 	AMD Ryzen 7 3780U 	9,131 	AMD
758 	Intel Core i5-7600K @ 3.80GHz 	9,130 	intel
759 	Intel Core i5-1035G1 @ 1.00GHz 	9,119 	intel
760 	Intel Core i7-6820HK @ 2.70GHz 	9,118 	intel
761 	Intel Xeon E3-1245 V2 @ 3.40GHz 	9,118 	intel
762 	AMD Opteron 6282 SE 	9,116 	AMD
763 	Intel Core i7-4790T @ 2.70GHz 	9,094 	intel
764 	Intel Core i7-990X @ 3.47GHz 	9,086 	intel
765 	Intel Xeon W3680 @ 3.33GHz 	9,081 	intel
766 	Intel Xeon E3-1265L v4 @ 2.30GHz 	9,060 	intel
767 	Intel Xeon E5-1620 @ 3.60GHz 	9,055 	intel
768 	Intel Core i7-6700T @ 2.80GHz 	9,037 	intel
769 	Intel Core i7-4900MQ @ 2.80GHz 	9,033 	intel
770 	AMD FX-8370 Eight-Core 	9,021 	AMD
771 	Intel Core i7-4850HQ @ 2.30GHz 	9,016 	intel
772 	AMD Opteron 6276 	9,011 	AMD
773 	AMD Ryzen 3 2300X 	9,007 	AMD
774 	Intel Core i7-3820 @ 3.60GHz 	8,998 	intel
775 	AMD Ryzen 7 PRO 2700U 	8,996 	AMD
776 	Intel Core i7-6820EQ @ 2.80GHz 	8,968 	intel
777 	Intel Xeon E5-2448L v2 @ 1.80GHz 	8,954 	intel
778 	Intel Core i7-4770HQ @ 2.20GHz 	8,948 	intel
779 	AMD FX-8350 Eight-Core 	8,948 	AMD
780 	Intel Core i5-10400H @ 2.60GHz 	8,939 	intel
781 	Intel Xeon E5-2623 v3 @ 3.00GHz 	8,937 	intel
782 	Intel Xeon X5690 @ 3.47GHz 	8,932 	intel
783 	Intel Xeon E3-1505M v5 @ 2.80GHz 	8,923 	intel
784 	Intel Core i7-3770S @ 3.10GHz 	8,893 	intel
785 	Intel Core i5-3170K @ 3.20GHz 	8,882 	intel
786 	Intel Xeon E5-2630 @ 2.30GHz 	8,877 	intel
787 	Intel Core i3-9100F @ 3.60GHz 	8,877 	intel
788 	Intel Xeon E3-1275L v3 @ 2.70GHz 	8,874 	intel
789 	Intel Core i3-10105F @ 3.70GHz 	8,874 	intel
790 	AMD Ryzen 5 PRO 2500U 	8,865 	AMD
791 	Intel Xeon E3-1230 V2 @ 3.30GHz 	8,855 	intel
792 	Intel Xeon W-2223 @ 3.60GHz 	8,853 	intel
793 	Intel Xeon E5-4610 v3 @ 1.70GHz 	8,853 	intel
794 	Intel Core i7-8650U @ 1.90GHz 	8,851 	intel
795 	Intel Xeon X5679 @ 3.20GHz 	8,845 	intel
796 	Intel Core i7-7700HQ @ 2.80GHz 	8,840 	intel
797 	Intel Xeon E5-2430 v2 @ 2.50GHz 	8,833 	intel
798 	Intel Core i3-10105 @ 3.70GHz 	8,809 	intel
799 	Intel Core i5-10210U @ 1.60GHz 	8,783 	intel
800 	Intel Core i7-980X @ 3.33GHz 	8,782 	intel
801 	Intel Core i7-3840QM @ 2.80GHz 	8,782 	intel
802 	Intel Core i7-6820HQ @ 2.70GHz 	8,781 	intel
803 	Intel Core i3-9300T @ 3.20GHz 	8,777 	intel
804 	Intel Core i5-7600 @ 3.50GHz 	8,773 	intel
805 	Intel Core i7-8665UE @ 1.70GHz 	8,731 	intel
806 	Intel Core i7-2700K @ 3.50GHz 	8,715 	intel
807 	Intel Xeon E5-2620 v2 @ 2.10GHz 	8,702 	intel
808 	Intel Xeon E3-1290 @ 3.60GHz 	8,699 	intel
809 	Intel Core i5-8365UE @ 1.60GHz 	8,698 	intel
810 	Intel Core i7-6700TE @ 2.40GHz 	8,696 	intel
811 	Intel Xeon E3-1268L v5 @ 2.40GHz 	8,695 	intel
812 	Intel Xeon E5-4617 @ 2.90GHz 	8,684 	intel
813 	Intel Xeon E5-2650L @ 1.80GHz 	8,676 	intel
814 	Apple A14 Bionic 	8,673 	via
815 	Intel Core i7-980 @ 3.33GHz 	8,665 	intel
816 	Intel Core i3-8300 @ 3.70GHz 	8,663 	intel
817 	Intel Core i7-4810MQ @ 2.80GHz 	8,650 	intel
818 	Intel Xeon E5-2420 v2 @ 2.20GHz 	8,629 	intel
819 	Intel Core i7-4770T @ 2.50GHz 	8,624 	intel
820 	Intel Xeon Silver 4112 @ 2.60GHz 	8,607 	intel
821 	Intel Core i7-4760HQ @ 2.10GHz 	8,595 	intel
822 	AMD Ryzen 5 3400GE 	8,565 	AMD
823 	AMD Ryzen Embedded V1756B 	8,559 	AMD
824 	Intel Xeon X5680 @ 3.33GHz 	8,550 	intel
825 	AMD Ryzen 5 3550H 	8,499 	AMD
826 	AMD Ryzen 7 2800H 	8,498 	AMD
827 	Intel Core i7-4800MQ @ 2.70GHz 	8,495 	intel
828 	Intel Xeon E3-1280 @ 3.50GHz 	8,473 	intel
829 	AMD Ryzen 5 PRO 3500U 	8,448 	AMD
830 	Intel Core i7-2600K @ 3.40GHz 	8,444 	intel
831 	Intel Xeon D-1539 @ 1.60GHz 	8,443 	intel
832 	Intel Core i7-3820QM @ 2.70GHz 	8,443 	intel
833 	Intel Core i3-8100B @ 3.60GHz 	8,431 	intel
834 	Intel Xeon E5-2643 @ 3.30GHz 	8,423 	intel
835 	Intel Xeon E5-1428L v2 @ 2.20GHz 	8,377 	intel
836 	AMD Ryzen 5 1400 	8,376 	AMD
837 	Intel Core i7-970 @ 3.20GHz 	8,375 	intel
838 	Intel Core i7-5700HQ @ 2.70GHz 	8,368 	intel
839 	AMD Ryzen 3 4300U 	8,363 	AMD
840 	Intel Core i3-10300T @ 3.00GHz 	8,355 	intel
841 	Intel Core i3-10105T @ 3.00GHz 	8,354 	intel
842 	Intel Xeon E3-1275 @ 3.40GHz 	8,348 	intel
843 	Intel Core i7-3740QM @ 2.70GHz 	8,331 	intel
844 	Intel Core i7-8550U @ 1.80GHz 	8,325 	intel
845 	Intel Xeon X5675 @ 3.07GHz 	8,303 	intel
846 	Intel Xeon E3-1225 v6 @ 3.30GHz 	8,294 	intel
847 	Intel Xeon E5-2450L @ 1.80GHz 	8,261 	intel
848 	AMD Ryzen 3 3200G 	8,259 	AMD
849 	Intel Core i7-4750HQ @ 2.00GHz 	8,249 	intel
850 	Intel Core i5-8350U @ 1.70GHz 	8,248 	intel
851 	Intel Core i7-5700EQ @ 2.60GHz 	8,239 	intel
852 	Intel Xeon E3-1270 @ 3.40GHz 	8,238 	intel
853 	Intel Core i5-8265U @ 1.60GHz 	8,226 	intel
854 	AMD Ryzen 3 PRO 3200G 	8,215 	AMD
855 	Intel Xeon E5-2623 v4 @ 2.60GHz 	8,208 	intel
856 	Apple M1 	8,207 	via
857 	Intel Core i7-3770T @ 2.50GHz 	8,203 	intel
858 	Intel Core i5-5675C @ 3.10GHz 	8,199 	intel
859 	Intel Core i7-2600 @ 3.40GHz 	8,194 	intel
860 	AMD Ryzen 5 3350G 	8,185 	AMD
861 	Intel Core i7-5675C @ 3.10GHz 	8,164 	intel
862 	Intel Xeon W3670 @ 3.20GHz 	8,152 	intel
863 	AMD Ryzen 3 PRO 3200GE 	8,147 	AMD
864 	Intel Xeon D-2123IT @ 2.20GHz 	8,140 	intel
865 	Intel Core i3-10305T @ 3.00GHz 	8,136 	intel
866 	Intel Core i7-6700HQ @ 2.60GHz 	8,133 	intel
867 	Intel Xeon E5-4620 @ 2.20GHz 	8,127 	intel
868 	Intel Core i7-3720QM @ 2.60GHz 	8,125 	intel
869 	AMD Ryzen 3 PRO 2200G 	8,106 	AMD
870 	Intel Core i5-7600T @ 2.80GHz 	8,097 	intel
871 	AMD Ryzen 5 3550U 	8,080 	AMD
872 	Intel Core i3-8100 @ 3.60GHz 	8,073 	intel
873 	Intel Core i5-6600K @ 3.50GHz 	8,057 	intel
874 	Intel Core i5-8269U @ 2.60GHz 	8,055 	intel
875 	Intel Xeon D-1559 @ 1.50GHz 	8,055 	intel
876 	Intel Core i5-5675R @ 3.10GHz 	8,054 	intel
877 	Intel Core i7-4722HQ @ 2.40GHz 	8,052 	intel
878 	Intel Core i5-7500 @ 3.40GHz 	8,020 	intel
879 	AMD FX-8320 Eight-Core 	8,019 	AMD
880 	Intel Xeon E3-1245 @ 3.30GHz 	8,019 	intel
881 	Intel Core i5-10210Y @ 1.00GHz 	8,004 	intel
882 	Intel Core i7-4720HQ @ 2.60GHz 	8,001 	intel
883 	AMD Ryzen 3 PRO 1300 	7,999 	AMD
884 	Intel Core i7-4710MQ @ 2.50GHz 	7,998 	intel
885 	11th Gen Intel Core i7-1185G7 @ 3.00GHz 	7,979 	intel
886 	Intel Core i7-1185G7 @ 3.00GHz 	7,979 	intel
887 	Intel Xeon E3-1220 v6 @ 3.00GHz 	7,976 	intel
888 	AMD Ryzen 3 PRO 2200GE 	7,975 	AMD
889 	Intel Xeon E3-1240 @ 3.30GHz 	7,958 	intel
890 	AMD Ryzen 5 2600H 	7,949 	AMD
891 	Intel Xeon D-1528 @ 1.90GHz 	7,946 	intel
892 	AMD Ryzen 5 2400GE 	7,932 	AMD
893 	Intel Xeon X5670 @ 2.93GHz 	7,928 	intel
894 	Intel Xeon E5-2620 @ 2.00GHz 	7,919 	intel
895 	Intel Xeon E3-1505L v6 @ 2.20GHz 	7,887 	intel
896 	Intel Core i7-4860EQ @ 1.80GHz 	7,875 	intel
897 	Intel Xeon E5-2630L @ 2.00GHz 	7,865 	intel
898 	Intel Xeon E5-2608L v3 @ 2.00GHz 	7,857 	intel
899 	Intel Xeon E3-1268L v3 @ 2.30GHz 	7,850 	intel
900 	Intel Xeon E3-1230 @ 3.20GHz 	7,848 	intel
901 	Intel Core i5-8260U @ 1.60GHz 	7,834 	intel
902 	Intel Xeon E3-1225 v5 @ 3.30GHz 	7,833 	intel
903 	Intel Xeon E-2104G @ 3.20GHz 	7,825 	intel
904 	AMD Opteron 6328 	7,813 	AMD
905 	AMD FX-8370E Eight-Core 	7,801 	AMD
906 	Intel Core i5-4690K @ 3.50GHz 	7,796 	intel
907 	Intel Xeon E3-1240L v5 @ 2.10GHz 	7,793 	intel
908 	Intel Core i5-9300HF @ 2.40GHz 	7,792 	intel
909 	Intel Xeon E3-1265L V2 @ 2.50GHz 	7,785 	intel
910 	Intel Core i5-8365U @ 1.60GHz 	7,784 	intel
911 	Intel Xeon W-2104 @ 3.20GHz 	7,782 	intel
912 	Intel Core i5-6600 @ 3.30GHz 	7,763 	intel
913 	AMD FX-8310 Eight-Core 	7,758 	AMD
914 	Intel Xeon E3-1220 v5 @ 3.00GHz 	7,740 	intel
915 	Intel Core i7-4710HQ @ 2.50GHz 	7,733 	intel
916 	Intel Xeon D-1537 @ 1.70GHz 	7,731 	intel
917 	Intel Core i7-4700HQ @ 2.40GHz 	7,727 	intel
918 	AMD FX-8300 Eight-Core 	7,718 	AMD
919 	AMD Athlon Gold PRO 3150G 	7,702 	AMD
920 	Intel Core i5-7440HQ @ 2.80GHz 	7,701 	intel
921 	Intel Core i7-4700MQ @ 2.40GHz 	7,690 	intel
922 	Intel Xeon E3-1235 @ 3.20GHz 	7,680 	intel
923 	AMD Opteron 6238 	7,673 	AMD
924 	[3-Way] Intel Xeon X7460 @ 2.66GHz 	7,672 	intel
925 	Intel Core i5-8250U @ 1.60GHz 	7,671 	intel
926 	AMD Ryzen Embedded V1605B 	7,667 	AMD
927 	Intel Core i5-4690 @ 3.50GHz 	7,661 	intel
928 	Intel Core i3-8300T @ 3.20GHz 	7,650 	intel
929 	Intel Core i5-4670K @ 3.40GHz 	7,632 	intel
930 	AMD Ryzen 3 3200GE 	7,631 	AMD
931 	AMD FX-8150 Eight-Core 	7,628 	AMD
932 	Intel Xeon X5660 @ 2.80GHz 	7,618 	intel
933 	Intel Core i7-4785T @ 2.20GHz 	7,611 	intel
934 	Intel Core i3-9100T @ 3.10GHz 	7,608 	intel
935 	ARM Cortex-A72 8 Core 0 MHz 	7,605 	via
936 	Intel Core i3-10100T @ 3.00GHz 	7,589 	intel
937 	Intel Core i3-9350K @ 4.00GHz 	7,586 	intel
938 	Intel Core i7-3630QM @ 2.40GHz 	7,585 	intel
939 	AMD Athlon Gold PRO 3150GE 	7,578 	AMD
940 	AMD FX-8320E Eight-Core 	7,545 	AMD
941 	Intel Xeon E3-1226 v3 @ 3.30GHz 	7,530 	intel
942 	Intel Xeon E3-1240L v3 @ 2.00GHz 	7,510 	intel
943 	Intel Core i7-4712HQ @ 2.30GHz 	7,507 	intel
944 	AMD Opteron 6366 HE 	7,503 	AMD
945 	Intel Core i7-10810U @ 1.10GHz 	7,500 	intel
946 	Intel Core i7-4702HQ @ 2.20GHz 	7,486 	intel
947 	Intel Core i3-8100T @ 3.10GHz 	7,472 	intel
948 	Intel Core i7-3610QM @ 2.30GHz 	7,466 	intel
949 	AMD Ryzen 5 3450U 	7,463 	AMD
950 	AMD Ryzen 3 1300X 	7,462 	AMD
951 	Intel Core i5-4670 @ 3.40GHz 	7,444 	intel
952 	Intel Core i5-4690S @ 3.20GHz 	7,435 	intel
953 	Intel Core i5-5575R @ 2.80GHz 	7,434 	intel
954 	Intel Xeon E5-1410 v2 @ 2.80GHz 	7,430 	intel
955 	Intel Xeon E5-2648L @ 1.80GHz 	7,426 	intel
956 	Intel Core i5-4670R @ 3.00GHz 	7,419 	intel
957 	AMD Ryzen 7 2700U 	7,417 	AMD
958 	Intel Core i5-4670K CPT @ 3.40GHz 	7,411 	intel
959 	Intel Xeon X5650 @ 2.67GHz 	7,409 	intel
960 	AMD Ryzen 3 PRO 3300U 	7,398 	AMD
961 	Intel Core i7-3615QM @ 2.30GHz 	7,379 	intel
962 	Intel Xeon E3-1205 v6 @ 3.00GHz 	7,360 	intel
963 	Intel Core i5-7400 @ 3.00GHz 	7,352 	intel
964 	Intel Core i7-3615QE @ 2.30GHz 	7,340 	intel
965 	AMD Ryzen 3 2200G 	7,326 	AMD
966 	AMD Ryzen 5 2500U 	7,326 	AMD
967 	Intel Xeon E5-1410 @ 2.80GHz 	7,312 	intel
968 	Intel Core i7-4765T @ 2.00GHz 	7,312 	intel
969 	Intel Core i5-6600T @ 2.70GHz 	7,310 	intel
970 	Intel Core i5-4670S @ 3.10GHz 	7,308 	intel
971 	Intel Core i5-4590 @ 3.30GHz 	7,305 	intel
972 	Intel Core i5-8265UC @ 1.60GHz 	7,300 	intel
973 	AMD Opteron 6281 	7,279 	AMD
974 	Intel Xeon E5-2430L @ 2.00GHz 	7,269 	intel
975 	Intel Xeon E5-1607 v4 @ 3.10GHz 	7,249 	intel
976 	Intel Core i5-6500 @ 3.20GHz 	7,240 	intel
977 	AMD Ryzen 5 3580U 	7,235 	AMD
978 	Intel Xeon E3-1230L v3 @ 1.80GHz 	7,231 	intel
979 	Intel Core i7-2960XM @ 2.70GHz 	7,220 	intel
980 	Intel Xeon E3-1225 v3 @ 3.20GHz 	7,210 	intel
981 	Intel Core i7-4712MQ @ 2.30GHz 	7,198 	intel
982 	AMD Ryzen 3 PRO 2300U 	7,188 	AMD
983 	AMD Ryzen Embedded V1807B 	7,185 	AMD
984 	Intel Core i7-4700EQ @ 2.40GHz 	7,180 	intel
985 	Intel Core i5-3570K @ 3.40GHz 	7,171 	intel
986 	Intel Core i7-10610U @ 1.80GHz 	7,134 	intel
987 	Intel Core i7-4702MQ @ 2.20GHz 	7,134 	intel
988 	Intel Core i5-4570 @ 3.20GHz 	7,125 	intel
989 	AMD Ryzen 3 2200GE 	7,124 	AMD
990 	Intel Core i5-3570 @ 3.40GHz 	7,109 	intel
991 	Intel Xeon E3-1220 v3 @ 3.10GHz 	7,104 	intel
992 	Intel Core i5-6402P @ 2.80GHz 	7,092 	intel
993 	Intel Xeon X5687 @ 3.60GHz 	7,086 	intel
994 	Intel Xeon E3-1505L v5 @ 2.00GHz 	7,082 	intel
995 	Intel Core i7-2600S @ 2.80GHz 	7,074 	intel
996 	AMD Ryzen 3 PRO 1200 	7,069 	AMD
997 	Intel CC150 @ 3.50GHz 	7,063 	intel
998 	Intel Xeon E5-2420 @ 1.90GHz 	7,045 	intel
999 	Intel Core i7-2920XM @ 2.50GHz 	7,038 	intel
1000 	Intel Core i5-7500T @ 2.70GHz 	7,037 	intel
1001 	Intel Xeon W-2102 @ 2.90GHz 	7,030 	intel
1002 	Intel Core i5-4590S @ 3.00GHz 	7,024 	intel
1003 	AMD FX-6350 Six-Core 	6,998 	AMD
1004 	Intel Core i7-2860QM @ 2.50GHz 	6,991 	intel
1005 	Intel Xeon X5677 @ 3.47GHz 	6,982 	intel
1006 	Intel Xeon D-1521 @ 2.40GHz 	6,980 	intel
1007 	Intel Xeon E5-1607 v3 @ 3.10GHz 	6,947 	intel
1008 	Intel Xeon Platinum 8151 @ 3.40GHz 	6,947 	intel
1009 	Intel Core i5-3550 @ 3.30GHz 	6,944 	intel
1010 	Intel Core i7-3632QM @ 2.20GHz 	6,941 	intel
1011 	Intel Xeon E5649 @ 2.53GHz 	6,936 	intel
1012 	AMD FX-6330 Six-Core 	6,916 	AMD
1013 	Intel Xeon E5-2609 v4 @ 1.70GHz 	6,915 	intel
1014 	Intel Core i5-3550S @ 3.00GHz 	6,910 	intel
1015 	Intel Xeon E5-2430 @ 2.20GHz 	6,878 	intel
1016 	Intel Xeon E3-1225 V2 @ 3.20GHz 	6,873 	intel
1017 	Intel Xeon L5639 @ 2.13GHz 	6,835 	intel
1018 	Intel Core i7-3612QM @ 2.10GHz 	6,826 	intel
1019 	Intel Core i5-7300HQ @ 2.50GHz 	6,803 	intel
1020 	Intel Core i5-4570S @ 2.90GHz 	6,789 	intel
1021 	AMD Opteron 6220 	6,785 	AMD
1022 	Intel Core i5-6440HQ @ 2.60GHz 	6,784 	intel
1023 	Intel Core i3-10100 @ 3.60GHz 	6,769 	intel
1024 	Intel Core i7-2840QM @ 2.40GHz 	6,766 	intel
1025 	Intel Core i5-6400 @ 2.70GHz 	6,765 	intel
1026 	Intel Core i5-4570R @ 2.70GHz 	6,753 	intel
1027 	Intel Core i5-3570S @ 3.10GHz 	6,750 	intel
1028 	AMD Ryzen 3 1200 	6,749 	AMD
1029 	AMD Opteron 6272 	6,748 	AMD
1030 	Intel Core i7-4770TE @ 2.30GHz 	6,732 	intel
1031 	Intel Core i5-4460 @ 3.20GHz 	6,710 	intel
1032 	Intel Core i5-3470 @ 3.20GHz 	6,699 	intel
1033 	Intel Xeon Bronze 3106 @ 1.70GHz 	6,698 	intel
1034 	Intel Core i7-3635QM @ 2.40GHz 	6,671 	intel
1035 	Intel Xeon E3-1220 V2 @ 3.10GHz 	6,671 	intel
1036 	Intel Core i5-2550K @ 3.40GHz 	6,669 	intel
1037 	AMD Opteron 4284 	6,660 	AMD
1038 	Intel Core i7-985 @ 3.47GHz 	6,641 	intel
1039 	Intel Core i7-2820QM @ 2.30GHz 	6,634 	intel
1040 	Intel Xeon E5-2430L v2 @ 2.40GHz 	6,627 	intel
1041 	Intel Core i3-7350K @ 4.20GHz 	6,623 	intel
1042 	Intel Core i7-3612QE @ 2.10GHz 	6,622 	intel
1043 	Intel Core i5-3475S @ 2.90GHz 	6,612 	intel
1044 	AMD FX-8120 Eight-Core 	6,597 	AMD
1045 	Intel Atom C3958 @ 2.00GHz 	6,585 	intel
1046 	Intel Core i7-2760QM @ 2.40GHz 	6,578 	intel
1047 	AMD Ryzen 5 3500U 	6,547 	AMD
1048 	Intel Core i3-7320 @ 4.10GHz 	6,541 	intel
1049 	Intel Xeon E3-1260L @ 2.40GHz 	6,534 	intel
1050 	Intel Core i5-3450 @ 3.10GHz 	6,524 	intel
1051 	Intel Core i7-7567U @ 3.50GHz 	6,502 	intel
1052 	Intel Core i5-4440 @ 3.10GHz 	6,498 	intel
1053 	Intel Xeon E5645 @ 2.40GHz 	6,484 	intel
1054 	Intel Core i5-6500TE @ 2.30GHz 	6,478 	intel
1055 	Intel Core i5-4690T @ 2.50GHz 	6,478 	intel
1056 	Intel Core i5-2500K @ 3.30GHz 	6,476 	intel
1057 	Intel Xeon E3-1235L v5 @ 2.00GHz 	6,470 	intel
1058 	Intel Core i7-3610QE @ 2.30GHz 	6,451 	intel
1059 	Intel Core i3-7300 @ 4.00GHz 	6,436 	intel
1060 	Intel Xeon W3580 @ 3.33GHz 	6,433 	intel
1061 	AMD Opteron 4280 	6,430 	AMD
1062 	Intel Core i5-7400T @ 2.40GHz 	6,427 	intel
1063 	Intel Core i7-6822EQ @ 2.00GHz 	6,427 	intel
1064 	Intel Xeon E5-1603 v4 @ 2.80GHz 	6,420 	intel
1065 	Intel Xeon X5672 @ 3.20GHz 	6,419 	intel
1066 	Intel Core i5-10310U @ 1.70GHz 	6,416 	intel
1067 	Intel Xeon L5640 @ 2.27GHz 	6,405 	intel
1068 	Intel Core i5-4460S @ 2.90GHz 	6,402 	intel
1069 	Intel Core i7-1060NG7 @ 1.20GHz 	6,400 	intel
1070 	AMD FX-6300 Six-Core 	6,385 	AMD
1071 	AMD Opteron 3380 	6,384 	AMD
1072 	Intel Core i5-3470S @ 2.90GHz 	6,361 	intel
1073 	Intel Core i5-2500 @ 3.30GHz 	6,328 	intel
1074 	Intel Core i5-4430 @ 3.00GHz 	6,320 	intel
1075 	Intel Core i3-1115G4 @ 3.00GHz 	6,320 	intel
1076 	Intel Core i5-6500T @ 2.50GHz 	6,273 	intel
1077 	AMD Ryzen 3 3350U 	6,266 	AMD
1078 	Intel Core i5-7442EQ @ 2.10GHz 	6,262 	intel
1079 	Intel Xeon Bronze 3204 @ 1.90GHz 	6,248 	intel
1080 	Intel Core i9-9880H @ 2.30GHz 	6,233 	intel
1081 	Intel Core i5-4440S @ 2.80GHz 	6,217 	intel
1082 	AMD FX-6130 Six-Core 	6,215 	AMD
1083 	Intel Core i5-3450S @ 2.80GHz 	6,212 	intel
1084 	Intel Core i5-4670T @ 2.30GHz 	6,206 	intel
1085 	Intel Xeon D-1622 @ 2.60GHz 	6,205 	intel
1086 	Intel Xeon E5-1607 v2 @ 3.00GHz 	6,199 	intel
1087 	AMD PRO A12-9800 	6,199 	AMD
1088 	Intel Core i7-8565UC @ 1.80GHz 	6,187 	intel
1089 	Intel Core i3-8109U @ 3.00GHz 	6,185 	intel
1090 	Intel Xeon W5590 @ 3.33GHz 	6,183 	intel
1091 	AMD Ryzen 3 2300U 	6,174 	AMD
1092 	AMD Opteron 6174 	6,171 	AMD
1093 	Intel Xeon E5-1603 v3 @ 2.80GHz 	6,167 	intel
1094 	Intel Core i5-2450P @ 3.20GHz 	6,144 	intel
1095 	Intel Core i5-3350P @ 3.10GHz 	6,144 	intel
1096 	Intel Core i7-975 @ 3.33GHz 	6,132 	intel
1097 	AMD FX-6200 Six-Core 	6,129 	AMD
1098 	Intel Core i7-2720QM @ 2.20GHz 	6,113 	intel
1099 	Intel Core i7-1185GRE @ 2.80GHz 	6,107 	intel
1100 	AMD Opteron 4334 	6,099 	AMD
1101 	Intel Xeon E3-1220 @ 3.10GHz 	6,097 	intel
1102 	AMD Ryzen 7 3700U 	6,092 	AMD
1103 	Intel Core i5-3340 @ 3.10GHz 	6,089 	intel
1104 	Intel Xeon W3570 @ 3.20GHz 	6,084 	intel
1105 	Intel Core i5-6300HQ @ 2.30GHz 	6,079 	intel
1106 	AMD PRO A12-8870 	6,067 	AMD
1107 	Intel Core i3-6320 @ 3.90GHz 	6,047 	intel
1108 	Intel Xeon E3-1265L @ 2.40GHz 	6,038 	intel
1109 	Intel Core i7-7660U @ 2.50GHz 	6,033 	intel
1110 	AMD FX-8140 Eight-Core 	6,033 	AMD
1111 	AMD FX-8100 Eight-Core 	6,018 	AMD
1112 	Intel Xeon X5647 @ 2.93GHz 	5,980 	intel
1113 	AMD Opteron 6234 	5,979 	AMD
1114 	AMD Opteron 3365 	5,963 	AMD
1115 	Intel Core i5-2400 @ 3.10GHz 	5,959 	intel
1116 	Intel Core i5-7360U @ 2.30GHz 	5,957 	intel
1117 	Intel Xeon W3565 @ 3.20GHz 	5,943 	intel
1118 	Intel Xeon E5-2609 v3 @ 1.90GHz 	5,940 	intel
1119 	Intel Core i5-3330 @ 3.00GHz 	5,935 	intel
1120 	Intel Core i3-10110U @ 2.10GHz 	5,930 	intel
1121 	Intel Xeon E3-1225 @ 3.10GHz 	5,909 	intel
1122 	Intel Core i5-4430S @ 2.70GHz 	5,906 	intel
1123 	Intel Core i3-1005G1 @ 1.20GHz 	5,905 	intel
1124 	Intel Core i5-3570T @ 2.30GHz 	5,901 	intel
1125 	Intel Core i7-2670QM @ 2.20GHz 	5,886 	intel
1126 	Intel Core i7-7560U @ 2.40GHz 	5,861 	intel
1127 	Intel Xeon E5-1607 @ 3.00GHz 	5,857 	intel
1128 	Intel Core i7-965 @ 3.20GHz 	5,856 	intel
1129 	AMD PRO A10-8850B 	5,852 	AMD
1130 	Intel Core i3-6300 @ 3.80GHz 	5,849 	intel
1131 	Intel Pentium Gold G5620 @ 4.00GHz 	5,848 	intel
1132 	Intel Core i5-3340S @ 2.80GHz 	5,846 	intel
1133 	Intel Xeon W5580 @ 3.20GHz 	5,836 	intel
1134 	Intel Core i7-960 @ 3.20GHz 	5,814 	intel
1135 	Intel Core i5-3335S @ 2.70GHz 	5,788 	intel
1136 	Intel Core i3-7100 @ 3.90GHz 	5,781 	intel
1137 	Intel Core i5-6440EQ @ 2.70GHz 	5,778 	intel
1138 	AMD Opteron 6212 	5,776 	AMD
1139 	AMD Opteron 4274 HE 	5,776 	AMD
1140 	Intel Core i7-2710QE @ 2.10GHz 	5,768 	intel
1141 	ZHAOXIN KaiXian KX-U6780A@2.7GHz 	5,760 	via
1142 	Intel Core i5-2320 @ 3.00GHz 	5,758 	intel
1143 	Intel Xeon D-1520 @ 2.20GHz 	5,755 	intel
1144 	AMD A8-7500 	5,755 	AMD
1145 	Intel Core i5-1030NG7 @ 1.10GHz 	5,745 	intel
1146 	Intel Pentium Gold G5600F @ 3.90GHz 	5,736 	intel
1147 	AMD FX-6120 Six-Core 	5,734 	AMD
1148 	AMD A10-7890K 	5,732 	AMD
1149 	AMD Phenom II X6 1100T 	5,729 	AMD
1150 	Intel Core i5-7440EQ @ 2.90GHz 	5,711 	intel
1151 	Intel Core i3-8145U @ 2.10GHz 	5,707 	intel
1152 	AMD PRO A10-8770 	5,707 	AMD
1153 	Intel Core i3-9100TE @ 2.20GHz 	5,705 	intel
1154 	Intel Xeon W3550 @ 3.07GHz 	5,696 	intel
1155 	Intel Pentium Gold G5600 @ 3.90GHz 	5,696 	intel
1156 	Intel Core i5-2380P @ 3.10GHz 	5,695 	intel
1157 	Intel Core i5-7260U @ 2.20GHz 	5,679 	intel
1158 	Intel Xeon X5570 @ 2.93GHz 	5,679 	intel
1159 	AMD PRO A10-9700 	5,677 	AMD
1160 	Intel Core i5-3330S @ 2.70GHz 	5,672 	intel
1161 	Intel Xeon Bronze 3104 @ 1.70GHz 	5,664 	intel
1162 	Intel Xeon X3480 @ 3.07GHz 	5,657 	intel
1163 	Intel Core i5-7287U @ 3.30GHz 	5,656 	intel
1164 	Intel Core i7-6567U @ 3.30GHz 	5,648 	intel
1165 	AMD PRO A10-8750B 	5,646 	AMD
1166 	AMD Opteron 4332 HE 	5,614 	AMD
1167 	Intel Core i5-4590T @ 2.00GHz 	5,602 	intel
1168 	Intel Core i3-4370 @ 3.80GHz 	5,599 	intel
1169 	Intel Core i5-6400T @ 2.20GHz 	5,598 	intel
1170 	AMD A10-8850 	5,598 	AMD
1171 	Intel Core i7-880 @ 3.07GHz 	5,595 	intel
1172 	AMD Phenom II X6 1090T 	5,585 	AMD
1173 	Intel Pentium Gold 7505 @ 2.00GHz 	5,578 	intel
1174 	Intel Xeon L5638 @ 2.00GHz 	5,556 	intel
1175 	Intel Core i7-950 @ 3.07GHz 	5,555 	intel
1176 	Intel Xeon E5-1603 @ 2.80GHz 	5,546 	intel
1177 	AMD Athlon X4 880K 	5,538 	AMD
1178 	Intel Core i5-2310 @ 2.90GHz 	5,536 	intel
1179 	Intel Core i7-2675QM @ 2.20GHz 	5,533 	intel
1180 	Intel Core i7-2630QM @ 2.00GHz 	5,529 	intel
1181 	Intel Core i7-10510Y @ 1.20GHz 	5,523 	intel
1182 	AMD A12-9800 	5,522 	AMD
1183 	AMD Athlon PRO 300GE 	5,522 	AMD
1184 	Intel Pentium Gold G5420 @ 3.80GHz 	5,518 	intel
1185 	AMD Athlon 300GE 	5,517 	AMD
1186 	Intel Core i3-6100 @ 3.70GHz 	5,490 	intel
1187 	AMD A10-7850K APU 	5,477 	AMD
1188 	AMD A10-7870K 	5,475 	AMD
1189 	Intel Xeon W3540 @ 2.93GHz 	5,472 	intel
1190 	AMD A8-8650 	5,470 	AMD
1191 	Intel Core i3-4360 @ 3.70GHz 	5,460 	intel
1192 	Intel Core i7-2635QM @ 2.00GHz 	5,456 	intel
1193 	Intel Xeon E5-2603 v4 @ 1.70GHz 	5,451 	intel
1194 	AMD Opteron 6176 SE 	5,446 	AMD
1195 	Intel Core i5-760S @ 2.53GHz 	5,440 	intel
1196 	AMD Athlon X4 860K 	5,432 	AMD
1197 	AMD A10-9700 	5,429 	AMD
1198 	Intel Core i7-875K @ 2.93GHz 	5,429 	intel
1199 	AMD PRO A8-8650B 	5,426 	AMD
1200 	AMD Athlon X4 845 	5,426 	AMD
1201 	AMD Opteron 4386 	5,419 	AMD
1202 	Intel Core i3-6098P @ 3.60GHz 	5,415 	intel
1203 	Intel Xeon X5550 @ 2.67GHz 	5,404 	intel
1204 	AMD Opteron 3280 	5,403 	AMD
1205 	Intel Xeon X5560 @ 2.80GHz 	5,399 	intel
1206 	AMD Athlon 3000G 	5,389 	AMD
1207 	AMD A10 PRO-7850B APU 	5,382 	AMD
1208 	AMD FX-6100 Six-Core 	5,379 	AMD
1209 	Intel Core i3-7300T @ 3.50GHz 	5,369 	intel
1210 	Intel Core i7-2715QE @ 2.10GHz 	5,365 	intel
1211 	Intel Xeon W3530 @ 2.80GHz 	5,359 	intel
1212 	Intel Core i7-940 @ 2.93GHz 	5,355 	intel
1213 	AMD Opteron 6164 HE 	5,351 	AMD
1214 	Intel Core i5-2300 @ 2.80GHz 	5,346 	intel
1215 	AMD Athlon 220GE 	5,346 	AMD
1216 	AMD Phenom II X6 1075T 	5,341 	AMD
1217 	Intel Core i7-870 @ 2.93GHz 	5,341 	intel
1218 	AMD FX-4350 Quad-Core 	5,335 	AMD
1219 	Intel Xeon D-1518 @ 2.20GHz 	5,322 	intel
1220 	AMD FX-4330 	5,321 	AMD
1221 	AMD A8-7680 	5,314 	AMD
1222 	Intel Core i5-2500S @ 2.70GHz 	5,313 	intel
1223 	AMD Athlon X4 950 	5,311 	AMD
1224 	AMD Athlon X4 870K 	5,307 	AMD
1225 	AMD PRO A8-9600 	5,296 	AMD
1226 	ARM Neoverse-N1 8 Core 0 MHz 	5,264 	via
1227 	Intel Xeon E5640 @ 2.67GHz 	5,263 	intel
1228 	AMD Opteron 6172 	5,261 	AMD
1229 	Intel Core i3-6300T @ 3.30GHz 	5,249 	intel
1230 	AMD Athlon PRO 200GE 	5,246 	AMD
1231 	Intel Pentium Gold G5500 @ 3.80GHz 	5,241 	intel
1232 	Intel Core i3-4340 @ 3.60GHz 	5,240 	intel
1233 	Intel Pentium G4620 @ 3.70GHz 	5,205 	intel
1234 	Intel Xeon E5-2418L @ 2.00GHz 	5,202 	intel
1235 	Haydn based on Qualcomm Technologies, Inc SM8350 	5,201 	via
1236 	Intel Core i5-7300U @ 2.60GHz 	5,191 	intel
1237 	Intel Core i3-4170 @ 3.70GHz 	5,189 	intel
1238 	Intel Pentium Gold G5400 @ 3.70GHz 	5,189 	intel
1239 	AMD PRO A12-8870E 	5,186 	AMD
1240 	AMD Ryzen Embedded V1404I 	5,180 	AMD
1241 	Intel Xeon E5-2603 v3 @ 1.60GHz 	5,172 	intel
1242 	Intel Core i7-7500U @ 2.70GHz 	5,170 	intel
1243 	Intel Core i7-7600U @ 2.80GHz 	5,170 	intel
1244 	Intel Pentium Gold G5420T @ 3.20GHz 	5,156 	intel
1245 	Intel Xeon E5-2609 v2 @ 2.50GHz 	5,149 	intel
1246 	Intel Core i7-930 @ 2.80GHz 	5,143 	intel
1247 	Qualcomm Technologies, Inc SM8250 	5,132 	via
1248 	AMD A10-7700K APU 	5,128 	AMD
1249 	Apple A13 Bionic 	5,125 	via
1250 	Intel Xeon X3470 @ 2.93GHz 	5,123 	intel
1251 	Intel Xeon X3460 @ 2.80GHz 	5,117 	intel
1252 	AMD Athlon 240GE 	5,114 	AMD
1253 	AMD Ryzen 3 PRO 2100GE 	5,113 	AMD
1254 	AMD A10 PRO-7800B APU 	5,108 	AMD
1255 	AMD FX-870K Quad Core 	5,105 	AMD
1256 	AMD A12-9800E 	5,104 	AMD
1257 	AMD Ryzen 3 3300U 	5,103 	AMD
1258 	Intel Core i5-7267U @ 3.10GHz 	5,098 	intel
1259 	Intel Core i3-4330 @ 3.50GHz 	5,096 	intel
1260 	Intel Pentium G4600 @ 3.60GHz 	5,093 	intel
1261 	AMD A8-7600 APU 	5,089 	AMD
1262 	Intel Xeon E5630 @ 2.53GHz 	5,088 	intel
1263 	AMD A10-7860K 	5,084 	AMD
1264 	AMD A8-7670K 	5,083 	AMD
1265 	AMD A10-8750 	5,082 	AMD
1266 	AMD Embedded R-Series RX-418GD Radeon R6 	5,068 	AMD
1267 	Intel Core i5-2405S @ 2.50GHz 	5,065 	intel
1268 	AMD Phenom II X6 1065T 	5,064 	AMD
1269 	Intel Xeon W3520 @ 2.67GHz 	5,059 	intel
1270 	Intel Core i3-4160 @ 3.60GHz 	5,056 	intel
1271 	AMD Ryzen Embedded V1202B 	5,051 	AMD
1272 	Intel Core i3-7100T @ 3.40GHz 	5,049 	intel
1273 	Intel Pentium Gold G5400T @ 3.10GHz 	5,048 	intel
1274 	AMD PRO A10-8770E 	5,045 	AMD
1275 	Intel Core i3-8130U @ 2.20GHz 	5,044 	intel
1276 	AMD Phenom II X6 1405T 	5,042 	AMD
1277 	AMD Ryzen Embedded R1606G 	5,040 	AMD
1278 	AMD Athlon X4 840 	5,037 	AMD
1279 	AMD Opteron 4365 EE 	5,025 	AMD
1280 	Intel Core i3-7101TE @ 3.40GHz 	5,016 	intel
1281 	AMD PRO A8-8670E 	5,015 	AMD
1282 	Intel Xeon E5-4603 @ 2.00GHz 	5,014 	intel
1283 	AMD A8-9600 	5,010 	AMD
1284 	AMD FX-4320 	5,009 	AMD
1285 	Intel Core i7-860 @ 2.80GHz 	5,009 	intel
1286 	Intel Core i5-6267U @ 2.90GHz 	4,999 	intel
1287 	AMD A10-7800 APU 	4,993 	AMD
1288 	AMD A10-6800B APU 	4,991 	AMD
1289 	Intel Core i7-4610M @ 3.00GHz 	4,981 	intel
1290 	Intel Core i7-870S @ 2.67GHz 	4,969 	intel
1291 	AMD Phenom II X6 1055T 	4,964 	AMD
1292 	Intel Core i3-4350 @ 3.60GHz 	4,963 	intel
1293 	Intel Core i5-2400S @ 2.50GHz 	4,963 	intel
1294 	AMD Ryzen 3 3200U 	4,955 	AMD
1295 	Intel Core i7-6650U @ 2.20GHz 	4,953 	intel
1296 	MT6893Z/CZA 	4,949 	via
1297 	Intel Core i7-5557U @ 3.10GHz 	4,943 	intel
1298 	Intel Core i5-4460T @ 1.90GHz 	4,942 	intel
1299 	Intel Core i3-4570T @ 2.90GHz 	4,934 	intel
1300 	AMD A8-7650K 	4,933 	AMD
1301 	AMD Athlon 200GE 	4,931 	AMD
1302 	Intel Core i5-24050S @ 2.50GHz 	4,928 	intel
1303 	Intel Core i7-920 @ 2.67GHz 	4,925 	intel
1304 	AMD PRO A10-9700E 	4,922 	AMD
1305 	Star based on Qualcomm Technologies, Inc SM8350 	4,907 	via
1306 	AMD Opteron X3421 APU 	4,899 	AMD
1307 	Intel Core i3-4150 @ 3.50GHz 	4,891 	intel
1308 	Intel Core i7-4600M @ 2.90GHz 	4,884 	intel
1309 	Venus based on Qualcomm Technologies, Inc SM8350 	4,881 	via
1310 	Intel Core i5-6360U @ 2.00GHz 	4,880 	intel
1311 	Intel Pentium G4560 @ 3.50GHz 	4,871 	intel
1312 	AMD Opteron 6274 	4,865 	AMD
1313 	AMD Athlon 300U 	4,864 	AMD
1314 	AMD A10-6800K APU 	4,863 	AMD
1315 	AMD FX-4170 Quad-Core 	4,859 	AMD
1316 	Intel Core i3-6100T @ 3.20GHz 	4,856 	intel
1317 	Intel Core i3-4370T @ 3.30GHz 	4,855 	intel
1318 	Intel Xeon E5620 @ 2.40GHz 	4,855 	intel
1319 	Intel Atom C3858 @ 2.00GHz 	4,852 	intel
1320 	Intel Xeon X5492 @ 3.40GHz 	4,844 	intel
1321 	Intel Core i5-4570T @ 2.90GHz 	4,827 	intel
1322 	Intel Core i7-6560U @ 2.20GHz 	4,820 	intel
1323 	AMD Phenom II X6 1045T 	4,817 	AMD
1324 	Intel Xeon X3450 @ 2.67GHz 	4,816 	intel
1325 	Intel Core i5-4340M @ 2.90GHz 	4,810 	intel
1326 	AMD A8 PRO-7600B APU 	4,808 	AMD
1327 	Intel Core i7-6600U @ 2.60GHz 	4,802 	intel
1328 	Intel Core i3-4130 @ 3.40GHz 	4,796 	intel
1329 	AMD PRO A12-9800E 	4,788 	AMD
1330 	AMD FX-770K Quad-Core 	4,782 	AMD
1331 	Intel Core i7-4578U @ 3.00GHz 	4,780 	intel
1332 	Hisilicon Kirin9000 	4,760 	via
1333 	Intel Xeon E5540 @ 2.53GHz 	4,758 	intel
1334 	Intel Core i3-7167U @ 2.80GHz 	4,757 	intel
1335 	ARM Neoverse-N1 6 Core 0 MHz 	4,756 	via
1336 	Intel Core i5-6287U @ 3.10GHz 	4,751 	intel
1337 	Intel Core i5-4470S @ 3.00GHz 	4,742 	intel
1338 	AMD A10-9700E 	4,741 	AMD
1339 	AMD Ryzen Embedded R1505G 	4,733 	AMD
1340 	AMD FX-9830P 	4,729 	AMD
1341 	Intel Xeon X5667 @ 3.07GHz 	4,722 	intel
1342 	Intel Core i7-860S @ 2.53GHz 	4,711 	intel
1343 	AMD Opteron 2435 	4,708 	AMD
1344 	AMD A10-6790K APU 	4,703 	AMD
1345 	AMD Athlon Silver PRO 3125GE 	4,701 	AMD
1346 	AMD Athlon X4 830 	4,701 	AMD
1347 	Intel Core i3-7100H @ 3.00GHz 	4,696 	intel
1348 	Qualcomm Snapdragon 8350 	4,683 	via
1349 	AMD FX-4300 Quad-Core 	4,682 	AMD
1350 	Hisilicon Kirin990 	4,681 	via
1351 	Intel Core i5-5287U @ 2.90GHz 	4,681 	intel
1352 	Qualcomm Technologies, Inc SM8350 	4,677 	via
1353 	Intel Atom C3758 @ 2.20GHz 	4,675 	intel
1354 	AMD A10-5800B APU 	4,669 	AMD
1355 	Intel Xeon X3380 @ 3.16GHz 	4,665 	intel
1356 	Intel Core i7-3540M @ 3.00GHz 	4,664 	intel
1357 	AMD Phenom II X6 1035T 	4,664 	AMD
1358 	Intel Core2 Extreme X9775 @ 3.20GHz 	4,646 	intel
1359 	AMD A10-5800K APU 	4,637 	AMD
1360 	AMD Ryzen 3 2200U 	4,637 	AMD
1361 	Intel Core i3-4360T @ 3.20GHz 	4,636 	intel
1362 	AMD Embedded R-Series RX-421BD 	4,635 	AMD
1363 	AMD Opteron 6136 	4,631 	AMD
1364 	Intel Core i5-4310M @ 2.70GHz 	4,627 	intel
1365 	AMD FX-7600P APU 	4,627 	AMD
1366 	Intel Core i5-7200U @ 2.50GHz 	4,616 	intel
1367 	Intel Xeon E5-2609 @ 2.40GHz 	4,616 	intel
1368 	Intel Core2 Extreme X9770 @ 3.20GHz 	4,611 	intel
1369 	AMD FX-B4150 Quad-Core 	4,611 	AMD
1370 	Intel Core i5-2500T @ 2.30GHz 	4,608 	intel
1371 	Intel Xeon E5530 @ 2.40GHz 	4,605 	intel
1372 	AMD A8-6500B APU 	4,603 	AMD
1373 	Intel Xeon X5470 @ 3.33GHz 	4,600 	intel
1374 	Intel Pentium 6805 @ 1.10GHz 	4,600 	intel
1375 	AMD A10-6700 APU 	4,597 	AMD
1376 	Intel Core2 Extreme X9750 @ 3.16GHz 	4,597 	intel
1377 	AMD Athlon X4 760K Quad Core 	4,594 	AMD
1378 	AMD FX-4150 Quad-Core 	4,594 	AMD
1379 	Intel Core i3-8121U @ 2.20GHz 	4,590 	intel
1380 	Qualcomm Technologies, Inc KONA 	4,584 	via
1381 	AMD A8-6600K APU 	4,584 	AMD
1382 	Intel Pentium Gold G5500T @ 3.20GHz 	4,577 	intel
1383 	Intel Xeon E5-2407 v2 @ 2.40GHz 	4,575 	intel
1384 	Intel Xeon X5482 @ 3.20GHz 	4,571 	intel
1385 	AMD Opteron X3418 APU 	4,569 	AMD
1386 	Samsung Exynos 2100 	4,560 	via
1387 	Intel Core 860 @ 2.80GHz 	4,555 	intel
1388 	AMD Athlon X4 750 Quad Core 	4,551 	AMD
1389 	AMD FX-670K Quad-Core 	4,550 	AMD
1390 	Intel Core i3-4170T @ 3.20GHz 	4,549 	intel
1391 	Intel Core i5-4400E @ 2.70GHz 	4,548 	intel
1392 	AMD Athlon Silver 3050GE 	4,545 	AMD
1393 	Intel Core i7-3520M @ 2.90GHz 	4,541 	intel
1394 	Intel Xeon X3440 @ 2.53GHz 	4,540 	intel
1395 	AMD FirePro A320 APU 	4,540 	AMD
1396 	Intel Core i7-6498DU @ 2.50GHz 	4,538 	intel
1397 	Intel Core i5-4210H @ 2.90GHz 	4,536 	intel
1398 	AMD Opteron 2431 	4,516 	AMD
1399 	AMD Opteron 6128 	4,505 	AMD
1400 	AMD A10-9630P 	4,497 	AMD
1401 	AMD Phenom II X4 980 	4,493 	AMD
1402 	Intel Core i5-4330M @ 2.80GHz 	4,488 	intel
1403 	Intel Core i3-4330T @ 3.00GHz 	4,486 	intel
1404 	Intel Core i5-3470T @ 2.90GHz 	4,482 	intel
1405 	AMD Ryzen 3 3250U 	4,472 	AMD
1406 	AMD Phenom II X4 975 	4,463 	AMD
1407 	Intel Pentium Gold G6600 @ 4.20GHz 	4,463 	intel
1408 	Intel Core i3-3250 @ 3.50GHz 	4,446 	intel
1409 	Renoir based on Qualcomm Technologies, Inc SM7350 	4,442 	via
1410 	Intel Xeon E5520 @ 2.27GHz 	4,435 	intel
1411 	Intel Xeon E5-2637 @ 3.00GHz 	4,433 	intel
1412 	Intel Core i5-4200H @ 2.80GHz 	4,432 	intel
1413 	Intel Core i3-3245 @ 3.40GHz 	4,429 	intel
1414 	Intel Core i5-3380M @ 2.90GHz 	4,428 	intel
1415 	Intel Core i7-6500U @ 2.50GHz 	4,428 	intel
1416 	Intel Core i5-3360M @ 2.80GHz 	4,425 	intel
1417 	Intel Xeon E3-1220L V2 @ 2.30GHz 	4,419 	intel
1418 	AMD Opteron 4184 	4,418 	AMD
1419 	Intel Core i3-4160T @ 3.10GHz 	4,416 	intel
1420 	Intel Core i5-4300M @ 2.60GHz 	4,407 	intel
1421 	Intel Core i5-5257U @ 2.70GHz 	4,401 	intel
1422 	AMD PRO A10-9700B 	4,393 	AMD
1423 	Intel Xeon L5520 @ 2.27GHz 	4,387 	intel
1424 	AMD A8-6500 APU 	4,384 	AMD
1425 	AMD A12-9730P 	4,381 	AMD
1426 	Intel Core i7-4558U @ 2.80GHz 	4,378 	intel
1427 	Intel Core i5-6300U @ 2.40GHz 	4,370 	intel
1428 	Intel Xeon L5630 @ 2.13GHz 	4,369 	intel
1429 	Intel Core i5-4278U @ 2.60GHz 	4,362 	intel
1430 	Intel Core i5-6260U @ 1.80GHz 	4,362 	intel
1431 	Intel Core i5-4288U @ 2.60GHz 	4,355 	intel
1432 	Intel Xeon L5530 @ 2.40GHz 	4,351 	intel
1433 	AMD A8-5600K APU 	4,340 	AMD
1434 	Intel Core i3-3225 @ 3.30GHz 	4,337 	intel
1435 	Intel Core i3-6100TE @ 2.70GHz 	4,337 	intel
1436 	Intel Xeon X5460 @ 3.16GHz 	4,336 	intel
1437 	Intel Core i7-4560U @ 1.60GHz 	4,329 	intel
1438 	AMD Phenom II X4 970 	4,327 	AMD
1439 	AMD PRO A12-8830B 	4,325 	AMD
1440 	Intel Core i3-2140 @ 3.50GHz 	4,325 	intel
1441 	Intel Core i5-8200Y @ 1.30GHz 	4,320 	intel
1442 	Apple A12 Bionic 	4,318 	via
1443 	AMD RX-427BB 	4,317 	AMD
1444 	Intel Core i7-5600U @ 2.60GHz 	4,312 	intel
1445 	Intel Core i3-3240 @ 3.40GHz 	4,311 	intel
1446 	Intel Pentium Silver N6000 @ 1.10GHz 	4,304 	intel
1447 	Intel Core i3-4350T @ 3.10GHz 	4,302 	intel
1448 	Intel Xeon X3370 @ 3.00GHz 	4,286 	intel
1449 	AMD FX-4200 Quad-Core 	4,279 	AMD
1450 	Intel Pentium Gold G6405 @ 4.10GHz 	4,274 	intel
1451 	Intel Pentium G4600T @ 3.00GHz 	4,272 	intel
1452 	Intel Xeon X5698 @ 4.40GHz 	4,272 	intel
1453 	Intel Core i7-5550U @ 2.00GHz 	4,271 	intel
1454 	Intel Core i3-4150T @ 3.00GHz 	4,267 	intel
1455 	Intel Core i5-2390T @ 2.70GHz 	4,262 	intel
1456 	AMD Phenom II X4 B70 	4,261 	AMD
1457 	AMD Athlon Gold 3150U 	4,259 	AMD
1458 	Intel Pentium Gold G6400 @ 4.00GHz 	4,259 	intel
1459 	Intel Core i5-3340M @ 2.70GHz 	4,254 	intel
1460 	AMD Athlon X4 750K Quad Core 	4,249 	AMD
1461 	Intel Core i3-6100H @ 2.70GHz 	4,246 	intel
1462 	Microsoft SQ2 @ 3.15 GHz 	4,242 	via
1463 	Intel Core i3-3220 @ 3.30GHz 	4,237 	intel
1464 	Intel Core i7-5650U @ 2.20GHz 	4,224 	intel
1465 	Intel Core i5-4308U @ 2.80GHz 	4,219 	intel
1466 	Intel Pentium Gold G6500 @ 4.10GHz 	4,208 	intel
1467 	AMD A10-5700 APU 	4,207 	AMD
1468 	Intel Xeon E5450 @ 3.00GHz 	4,200 	intel
1469 	Intel Core i5-4210M @ 2.60GHz 	4,195 	intel
1470 	AMD Ryzen Embedded V1500B 	4,194 	AMD
1471 	AMD Phenom II X4 965 	4,191 	AMD
1472 	Intel Pentium G4520 @ 3.60GHz 	4,184 	intel
1473 	Intel Core i7-3687U @ 2.10GHz 	4,183 	intel
1474 	Intel Core i3-8145UE @ 2.20GHz 	4,181 	intel
1475 	AMD Phenom II X4 B65 	4,177 	AMD
1476 	Apple A11 Bionic 	4,175 	via
1477 	Intel Core2 Quad Q9650 @ 3.00GHz 	4,169 	intel
1478 	Intel Core2 Extreme X9650 @ 3.00GHz 	4,164 	intel
1479 	Intel Core i5-6198DU @ 2.30GHz 	4,164 	intel
1480 	AMD FX-4130 Quad-Core 	4,163 	AMD
1481 	Hisilicon Kirin985 	4,162 	via
1482 	AMD PRO A12-9800B 	4,158 	AMD
1483 	AMD PRO A12-8800B 	4,154 	AMD
1484 	AMD FX-8800P 	4,147 	AMD
1485 	AMD Athlon II X4 559 	4,142 	AMD
1486 	Intel Core i3-4130T @ 2.90GHz 	4,140 	intel
1487 	Intel Core i7-3555LE @ 2.50GHz 	4,130 	intel
1488 	AMD Phenom II X4 B99 	4,130 	AMD
1489 	Intel Xeon E5472 @ 3.00GHz 	4,126 	intel
1490 	Intel Xeon X5450 @ 3.00GHz 	4,124 	intel
1491 	Intel Core i5-3320M @ 2.60GHz 	4,114 	intel
1492 	Intel Core i7-4600U @ 2.10GHz 	4,107 	intel
1493 	Snapdragon 8cx Gen 2 @ 3.1 	4,103 	via
1494 	Intel Core i5-4258U @ 2.40GHz 	4,078 	intel
1495 	Intel Pentium G4560T @ 2.90GHz 	4,076 	intel
1496 	Intel Celeron J6413 @ 1.80GHz 	4,075 	intel
1497 	AMD FX-4100 Quad-Core 	4,069 	AMD
1498 	Intel Core i3-2130 @ 3.40GHz 	4,062 	intel
1499 	Intel Core i5-8210Y @ 1.60GHz 	4,057 	intel
1500 	AMD FX-7600P 	4,051 	AMD
1501 	AMD Phenom II X4 B60 	4,047 	AMD
1502 	Intel Xeon X5472 @ 3.00GHz 	4,034 	intel
1503 	Intel Core i5-4200M @ 2.50GHz 	4,034 	intel
1504 	Intel Core i3-7130U @ 2.70GHz 	4,033 	intel
1505 	Intel Core i3-3210 @ 3.20GHz 	4,032 	intel
1506 	Intel Core i3-2125 @ 3.30GHz 	4,025 	intel
1507 	Microsoft ARM SQ1 @ 3.0 GHz 	4,024 	via
1508 	Intel Core i5-6200U @ 2.30GHz 	4,014 	intel
1509 	AMD Opteron 3350 HE 	4,009 	AMD
1510 	AMD Athlon X4 740 Quad Core 	4,009 	AMD
1511 	Intel Xeon X3363 @ 2.83GHz 	4,008 	intel
1512 	Intel Pentium Gold G6500T @ 3.50GHz 	4,005 	intel
1513 	AMD PRO A8-9600B 	4,004 	AMD
1514 	AMD FX-9800P 	3,998 	AMD
1515 	AMD A8-5500 APU 	3,993 	AMD
1516 	AMD A12-9720P 	3,989 	AMD
1517 	Intel Core i7-3667U @ 2.00GHz 	3,988 	intel
1518 	AMD PRO A10-8730B 	3,985 	AMD
1519 	Intel Xeon E5440 @ 2.83GHz 	3,976 	intel
1520 	Intel Core2 Quad Q9550 @ 2.83GHz 	3,972 	intel
1521 	Intel Core i7-5500U @ 2.40GHz 	3,970 	intel
1522 	Intel Core i7-4650U @ 1.70GHz 	3,967 	intel
1523 	Intel Xeon X3360 @ 2.83GHz 	3,955 	intel
1524 	AMD A8-5500B APU 	3,954 	AMD
1525 	Intel Core2 Quad Q9705 @ 3.16GHz 	3,947 	intel
1526 	Intel Core i5-4402E @ 1.60GHz 	3,947 	intel
1527 	Intel Core i7-940XM @ 2.13GHz 	3,945 	intel
1528 	AMD Phenom Ultra X4 24500 	3,945 	AMD
1529 	Intel Xeon E5-2407 @ 2.20GHz 	3,944 	intel
1530 	Intel Core i5-3230M @ 2.60GHz 	3,938 	intel
1531 	Intel Core i7-2640M @ 2.80GHz 	3,936 	intel
1532 	AMD Phenom II X4 955 	3,932 	AMD
1533 	Intel Core i7-4510U @ 2.00GHz 	3,929 	intel
1534 	Intel Core i3-2120 @ 3.30GHz 	3,925 	intel
1535 	Qualcomm Technologies, Inc SM8150 	3,909 	via
1536 	Qualcomm Technologies, Inc SM8150P 	3,895 	via
1537 	Intel Core i5-760 @ 2.80GHz 	3,889 	intel
1538 	AMD Ryzen 5 3500C with Radeon Vega Mobile Gfx 	3,889 	AMD
1539 	AMD Ryzen 5 3500C 	3,889 	AMD
1540 	Intel Pentium G3258 @ 3.20GHz 	3,886 	intel
1541 	Intel Xeon E5462 @ 2.80GHz 	3,885 	intel
1542 	AMD Phenom II X4 B97 	3,883 	AMD
1543 	Intel Core i3-4110M @ 2.60GHz 	3,873 	intel
1544 	Intel Xeon L3360 @ 2.83GHz 	3,864 	intel
1545 	Intel Core i3-21050 @ 3.10GHz 	3,862 	intel
1546 	AMD Phenom II X4 B55 	3,859 	AMD
1547 	Intel Xeon X3353 @ 2.66GHz 	3,853 	intel
1548 	Intel Xeon X3350 @ 2.66GHz 	3,847 	intel
1549 	MT6889Z/CZA 	3,846 	via
1550 	Intel Core i7-6660U @ 2.40GHz 	3,845 	intel
1551 	Intel Core i7-3537U @ 2.00GHz 	3,842 	intel
1552 	Intel Xeon L3426 @ 1.87GHz 	3,837 	intel
1553 	Intel Core i7-2620M @ 2.70GHz 	3,837 	intel
1554 	Intel Xeon L7455 @ 2.13GHz 	3,836 	intel
1555 	Intel Core i3-6157U @ 2.40GHz 	3,835 	intel
1556 	AMD Athlon II X4 555 	3,830 	AMD
1557 	Intel Core i5-4570TE @ 2.70GHz 	3,827 	intel
1558 	Intel Core i5-3210M @ 2.50GHz 	3,823 	intel
1559 	AMD Athlon II X4 553 	3,814 	AMD
1560 	AMD Opteron 8439 SE 	3,813 	AMD
1561 	Intel Pentium D1508 @ 2.20GHz 	3,813 	intel
1562 	Snapdragon 8cx @ 2.84 GHz 	3,810 	via
1563 	Intel Atom C2750 @ 2.40GHz 	3,806 	intel
1564 	Intel Core i5-5300U @ 2.30GHz 	3,806 	intel
1565 	AMD A10-9600P 	3,794 	AMD
1566 	Intel Pentium G4500 @ 3.50GHz 	3,794 	intel
1567 	Intel Celeron N5100 @ 1.10GHz 	3,790 	intel
1568 	Intel Core i7-4500U @ 1.80GHz 	3,790 	intel
1569 	Intel Core i3-7100U @ 2.40GHz 	3,787 	intel
1570 	AMD Phenom II X4 960T 	3,787 	AMD
1571 	Intel Core i5-3610ME @ 2.70GHz 	3,786 	intel
1572 	Intel Core i5-2540M @ 2.60GHz 	3,782 	intel
1573 	Intel Xeon E5430 @ 2.66GHz 	3,774 	intel
1574 	Intel Core i3-6100E @ 2.70GHz 	3,769 	intel
1575 	Intel Xeon E5-2603 v2 @ 1.80GHz 	3,766 	intel
1576 	Intel Core i7-7Y75 @ 1.30GHz 	3,764 	intel
1577 	Intel Core2 Quad Q9450 @ 2.66GHz 	3,761 	intel
1578 	Intel Pentium N6415 @ 1.20GHz 	3,760 	intel
1579 	AMD Phenom II X4 973 	3,759 	AMD
1580 	Intel Core i7-920XM @ 2.00GHz 	3,753 	intel
1581 	Intel Core i5-2560M @ 2.70GHz 	3,752 	intel
1582 	Intel Core i5-4310U @ 2.00GHz 	3,752 	intel
1583 	AMD Phenom II X4 977 	3,750 	AMD
1584 	Intel Core i7-4610Y @ 1.70GHz 	3,746 	intel
1585 	Intel Pentium Gold G6405T @ 3.50GHz 	3,746 	intel
1586 	Intel Core i5-4300U @ 1.90GHz 	3,742 	intel
1587 	Intel Core i5-7Y57 @ 1.20GHz 	3,737 	intel
1588 	Intel Core i3-2102 @ 3.10GHz 	3,736 	intel
1589 	AMD A12-9700P 	3,725 	AMD
1590 	Intel Xeon L5430 @ 2.66GHz 	3,716 	intel
1591 	Intel Xeon L5506 @ 2.13GHz 	3,715 	intel
1592 	Intel Core i7-4550U @ 1.50GHz 	3,713 	intel
1593 	Intel Pentium G3470 @ 3.60GHz 	3,706 	intel
1594 	Intel Pentium G3450 @ 3.40GHz 	3,704 	intel
1595 	Intel Core i3-2105 @ 3.10GHz 	3,704 	intel
1596 	AMD Phenom II X4 B50 	3,702 	AMD
1597 	Intel Core i3-3220T @ 2.80GHz 	3,698 	intel
1598 	AMD Phenom II X4 B95 	3,698 	AMD
1599 	AMD A10-9620P 	3,697 	AMD
1600 	Intel Core i5-750 @ 2.67GHz 	3,694 	intel
1601 	AMD A10-6700T APU 	3,693 	AMD
1602 	Intel Core i3-2100 @ 3.10GHz 	3,688 	intel
1603 	Intel Core i3-3240T @ 2.90GHz 	3,686 	intel
1604 	Intel Core i5-2510E @ 2.50GHz 	3,676 	intel
1605 	AMD Opteron 4170 HE 	3,664 	AMD
1606 	AMD A9-9820 	3,662 	AMD
1607 	AMD Phenom II X4 945 	3,662 	AMD
1608 	Intel Core i3-5157U @ 2.50GHz 	3,661 	intel
1609 	Qualcomm Technologies, Inc SM8150_Plus 	3,659 	via
1610 	Intel Core2 Extreme Q6800 @ 2.93GHz 	3,651 	intel
1611 	Intel Core i3-10110Y @ 1.00GHz 	3,639 	intel
1612 	Intel Core2 Extreme Q6850 @ 3.00GHz 	3,635 	intel
1613 	Intel Core i5-3437U @ 1.90GHz 	3,634 	intel
1614 	AMD A10-7400P 	3,633 	AMD
1615 	AMD Phenom FX-7750 Quad-Core 	3,616 	AMD
1616 	Hisilicon Kirin980 	3,612 	via
1617 	Intel Core m3-8100Y @ 1.10GHz 	3,612 	intel
1618 	Intel Pentium Gold G6400T @ 3.40GHz 	3,610 	intel
1619 	Intel Core i5-4350U @ 1.40GHz 	3,610 	intel
1620 	AMD Phenom II X4 840T 	3,601 	AMD
1621 	Intel Core i3-6100U @ 2.30GHz 	3,600 	intel
1622 	Intel Pentium G3460 @ 3.50GHz 	3,593 	intel
1623 	AMD Phenom II X4 940 	3,591 	AMD
1624 	Intel Core i7-8500Y @ 1.50GHz 	3,590 	intel
1625 	Intel Core i7-3517U @ 1.90GHz 	3,589 	intel
1626 	Intel Core i5-2520M @ 2.50GHz 	3,588 	intel
1627 	Intel Core i5-5250U @ 1.60GHz 	3,585 	intel
1628 	Intel Core i5-7Y54 @ 1.20GHz 	3,584 	intel
1629 	AMD PRO A10-8700B 	3,583 	AMD
1630 	Intel Xeon E5-2603 @ 1.80GHz 	3,580 	intel
1631 	AMD Athlon II X4 651 Quad-Core 	3,569 	AMD
1632 	Intel Core2 Quad Q9505 @ 2.83GHz 	3,569 	intel
1633 	Intel Xeon E3-1220L @ 2.20GHz 	3,563 	intel
1634 	MT6875 	3,561 	via
1635 	MediaTek MT6873 	3,557 	via
1636 	Intel Core i5-4260U @ 1.40GHz 	3,557 	intel
1637 	Intel Pentium G4400 @ 3.30GHz 	3,556 	intel
1638 	AMD PRO A8-8600B 	3,553 	AMD
1639 	Intel Core m3-7Y30 @ 1.00GHz 	3,552 	intel
1640 	Intel Core i3-7020U @ 2.30GHz 	3,551 	intel
1641 	AMD A8-3870K APU 	3,549 	AMD
1642 	Intel Core i5-3427U @ 1.80GHz 	3,548 	intel
1643 	AMD Phenom II X4 850 	3,547 	AMD
1644 	Intel Core2 Quad Q9500 @ 2.83GHz 	3,546 	intel
1645 	AMD Opteron 2384 	3,538 	AMD
1646 	AMD Opteron 2386 SE 	3,538 	AMD
1647 	Intel Xeon E5-2403 @ 1.80GHz 	3,523 	intel
1648 	Intel Core i5-5350U @ 1.80GHz 	3,517 	intel
1649 	Intel Core i5-680 @ 3.60GHz 	3,513 	intel
1650 	AMD Phenom II X4 840 	3,510 	AMD
1651 	Intel Xeon E5420 @ 2.50GHz 	3,502 	intel
1652 	Intel Xeon L5420 @ 2.50GHz 	3,501 	intel
1653 	Intel Core m7-6Y75 @ 1.20GHz 	3,499 	intel
1654 	Intel Xeon X5365 @ 3.00GHz 	3,491 	intel
1655 	AMD Phenom II 42 TWKR Black Edition 	3,489 	AMD
1656 	Intel Core i5-5200U @ 2.20GHz 	3,486 	intel
1657 	AMD Athlon II X4 650 	3,479 	AMD
1658 	AMD Athlon II X4 645 	3,474 	AMD
1659 	Intel Core i3-1000NG4 @ 1.10GHz 	3,472 	intel
1660 	Intel Core i3-4100M @ 2.50GHz 	3,471 	intel
1661 	Intel Pentium G4500T @ 3.00GHz 	3,471 	intel
1662 	AMD A8-3850 APU 	3,468 	AMD
1663 	AMD Phenom II X4 B45 	3,467 	AMD
1664 	Samsung Exynos 9825 	3,466 	via
1665 	Intel Core2 Extreme Q9300 @ 2.53GHz 	3,459 	intel
1666 	Intel Core i5-4250U @ 1.30GHz 	3,449 	intel
1667 	AMD A10-8700P 	3,446 	AMD
1668 	Quad-Core AMD Opteron 1385 	3,442 	AMD
1669 	Intel Celeron G4930 @ 3.20GHz 	3,439 	intel
1670 	AMD Phenom II X4 830 	3,434 	AMD
1671 	Intel Xeon Platinum 8167M @ 2.00GHz 	3,431 	intel
1672 	Quad-Core AMD Opteron 1389 	3,427 	AMD
1673 	Intel Xeon X3230 @ 2.66GHz 	3,425 	intel
1674 	AMD Phenom II X4 925 	3,421 	AMD
1675 	Intel Xeon E5-2403 v2 @ 1.80GHz 	3,418 	intel
1676 	Intel Core2 Extreme Q9200 @ 2.40GHz 	3,415 	intel
1677 	Intel Core i3-3130M @ 2.60GHz 	3,405 	intel
1678 	Intel Pentium G3420 @ 3.20GHz 	3,404 	intel
1679 	Intel Core i7-840QM @ 1.87GHz 	3,403 	intel
1680 	Intel Core i5-4210U @ 1.70GHz 	3,402 	intel
1681 	AMD Phenom II X4 820 	3,400 	AMD
1682 	Intel Core i5-655K @ 3.20GHz 	3,399 	intel
1683 	AMD Phenom II X4 920 	3,399 	AMD
1684 	Intel Xeon E5607 @ 2.27GHz 	3,397 	intel
1685 	Intel Core i5-2450M @ 2.50GHz 	3,396 	intel
1686 	Intel Pentium G3430 @ 3.30GHz 	3,395 	intel
1687 	AMD Phenom II X4 B40 	3,394 	AMD
1688 	Intel Pentium G2140 @ 3.30GHz 	3,384 	intel
1689 	AMD Phenom II X4 B35 	3,383 	AMD
1690 	Intel Celeron N5105 @ 2.00GHz 	3,376 	intel
1691 	Intel Xeon X3330 @ 2.66GHz 	3,375 	intel
1692 	Intel Xeon L5410 @ 2.33GHz 	3,370 	intel
1693 	Intel Pentium G3260 @ 3.30GHz 	3,370 	intel
1694 	Intel Core m5-6Y54 @ 1.10GHz 	3,367 	intel
1695 	Intel Xeon X3430 @ 2.40GHz 	3,361 	intel
1696 	MediaTek MT6853T 	3,357 	via
1697 	AMD Phenom II X4 B93 	3,355 	AMD
1698 	AMD Athlon II X4 641 Quad-Core 	3,346 	AMD
1699 	Intel Core2 Quad Q9400 @ 2.66GHz 	3,344 	intel
1700 	Intel Atom C2750 @ 2.41GHz 	3,344 	intel
1701 	AMD A10-5750M APU 	3,343 	AMD
1702 	MT6853V/TNZA 	3,333 	via
1703 	AMD Phenom II X4 B25 	3,330 	AMD
1704 	Intel Core i7-3517UE @ 1.70GHz 	3,323 	intel
1705 	AMD A8-7200P 	3,319 	AMD
1706 	Intel Pentium Silver J5040 @ 2.00GHz 	3,319 	intel
1707 	Intel Celeron G4920 @ 3.20GHz 	3,318 	intel
1708 	AMD Athlon II X4 640 	3,313 	AMD
1709 	Intel Core i5-2515E @ 2.50GHz 	3,313 	intel
1710 	Intel Core i5-670 @ 3.47GHz 	3,310 	intel
1711 	Intel Xeon X3320 @ 2.50GHz 	3,309 	intel
1712 	AMD Athlon Silver 3050U 	3,306 	AMD
1713 	Intel Pentium G3440 @ 3.30GHz 	3,304 	intel
1714 	Intel Core i5-2415M @ 2.30GHz 	3,299 	intel
1715 	Intel Xeon L5609 @ 1.87GHz 	3,298 	intel
1716 	Intel Core i5-4200U @ 1.60GHz 	3,290 	intel
1717 	Intel Core2 Quad Q6700 @ 2.66GHz 	3,287 	intel
1718 	Intel Celeron G4900 @ 3.10GHz 	3,284 	intel
1719 	Intel Core i5-2430M @ 2.40GHz 	3,280 	intel
1720 	Intel Xeon E5410 @ 2.33GHz 	3,267 	intel
1721 	Intel Core i3-7102E @ 2.10GHz 	3,266 	intel
1722 	AMD Opteron 3260 HE 	3,259 	AMD
1723 	Intel Pentium G3250 @ 3.20GHz 	3,254 	intel
1724 	AMD Phenom II X4 910e 	3,253 	AMD
1725 	AMD Phenom II X4 910 	3,252 	AMD
1726 	AMD A8-8600P 	3,248 	AMD
1727 	Intel Core i5-660 @ 3.33GHz 	3,247 	intel
1728 	Intel Pentium 4417U @ 2.30GHz 	3,246 	intel
1729 	AMD Athlon II X4 635 	3,243 	AMD
1730 	Intel Core i3-4000M @ 2.40GHz 	3,242 	intel
1731 	Intel Core2 Quad Q9100 @ 2.26GHz 	3,242 	intel
1732 	Intel Core m5-6Y57 @ 1.10GHz 	3,241 	intel
1733 	AMD PRO A6-9500 	3,239 	AMD
1734 	Intel Core i5-2435M @ 2.40GHz 	3,239 	intel
1735 	Qualcomm Technologies, Inc SM7225 	3,237 	via
1736 	Intel Core i7-820QM @ 1.73GHz 	3,228 	intel
1737 	ARM Neoverse-N1 4 Core 0 MHz 	3,226 	via
1738 	Intel Core i5-3337U @ 1.80GHz 	3,223 	intel
1739 	AMD A8-6500T APU 	3,221 	AMD
1740 	Intel Core i7-3689Y @ 1.50GHz 	3,220 	intel
1741 	Intel Core i3-3120M @ 2.50GHz 	3,219 	intel
1742 	Intel Pentium G4400T @ 2.90GHz 	3,219 	intel
1743 	Intel Xeon X5355 @ 2.66GHz 	3,218 	intel
1744 	AMD A10 PRO-7350B APU 	3,213 	AMD
1745 	AMD FX-7500 APU 	3,212 	AMD
1746 	Intel Pentium G2130 @ 3.20GHz 	3,211 	intel
1747 	Intel Core i3-4330TE @ 2.40GHz 	3,201 	intel
1748 	Intel Core i7-740QM @ 1.73GHz 	3,199 	intel
1749 	AMD Athlon II X4 638 Quad-Core 	3,198 	AMD
1750 	Intel Core i3-6102E @ 1.90GHz 	3,196 	intel
1751 	Samsung Exynos 9810 	3,195 	via
1752 	AMD A6-3670 APU 	3,190 	AMD
1753 	Intel Core i5-661 @ 3.33GHz 	3,182 	intel
1754 	Intel Core i3-5020U @ 2.20GHz 	3,181 	intel
1755 	AMD Opteron 2378 	3,179 	AMD
1756 	AMD Athlon X4 640 	3,172 	AMD
1757 	AMD Ryzen Embedded R1305G 	3,170 	AMD
1758 	AMD A6-7480 	3,168 	AMD
1759 	Intel Xeon X3323 @ 2.50GHz 	3,167 	intel
1760 	Intel Core2 Quad Q8400 @ 2.66GHz 	3,167 	intel
1761 	AMD Opteron 4162 EE 	3,166 	AMD
1762 	Intel Core i5-2410M @ 2.30GHz 	3,165 	intel
1763 	Intel Atom C2758 @ 2.40GHz 	3,162 	intel
1764 	Intel Core i7-2655LE @ 2.20GHz 	3,161 	intel
1765 	Intel Core2 Quad Q9300 @ 2.50GHz 	3,161 	intel
1766 	AMD Phenom 9850B Quad-Core 	3,160 	AMD
1767 	Samsung Exynos 9820 	3,160 	via
1768 	Intel Core i3-2120T @ 2.60GHz 	3,160 	intel
1769 	Intel Pentium G3240 @ 3.10GHz 	3,159 	intel
1770 	AMD A6-3650 APU 	3,156 	AMD
1771 	AMD Athlon II X4 631 Quad-Core 	3,153 	AMD
1772 	Intel Pentium 5405U @ 2.30GHz 	3,152 	intel
1773 	Intel Celeron G3900 @ 2.80GHz 	3,149 	intel
1774 	Intel Pentium 4415U @ 2.30GHz 	3,141 	intel
1775 	MT6833V/NZA 	3,140 	via
1776 	Intel Xeon E5507 @ 2.27GHz 	3,137 	intel
1777 	AMD Athlon II X4 630 	3,135 	AMD
1778 	Intel Pentium G3220 @ 3.00GHz 	3,132 	intel
1779 	AMD A8-3820 APU 	3,129 	AMD
1780 	AMD Phenom II X4 810 	3,124 	AMD
1781 	Qualcomm Technologies, Inc SM7250 	3,118 	via
1782 	Intel Xeon E7- 2830 @ 2.13GHz 	3,118 	intel
1783 	AMD R-464L APU 	3,117 	AMD
1784 	Intel Celeron G3920 @ 2.90GHz 	3,113 	intel
1785 	AMD A10-4600M APU 	3,112 	AMD
1786 	MT6833 	3,106 	via
1787 	AMD A6-8550 	3,104 	AMD
1788 	Intel Core i5-650 @ 3.20GHz 	3,102 	intel
1789 	Intel Pentium G3440T @ 2.80GHz 	3,101 	intel
1790 	Intel Core i3-6006U @ 2.00GHz 	3,090 	intel
1791 	Intel Core i5-3317U @ 1.70GHz 	3,088 	intel
1792 	Intel Xeon X3220 @ 2.40GHz 	3,087 	intel
1793 	AMD Phenom II X4 905e 	3,087 	AMD
1794 	AMD A10-5757M APU 	3,084 	AMD
1795 	Intel Pentium G2120 @ 3.10GHz 	3,081 	intel
1796 	Intel Core i3-3110M @ 2.40GHz 	3,076 	intel
1797 	Intel Core i3-2330E @ 2.20GHz 	3,073 	intel
1798 	AMD Opteron 2427 	3,069 	AMD
1799 	AMD Phenom II X3 B77 	3,067 	AMD
1800 	Intel Core i7 860 @ 2.80GHz 	3,067 	intel
1801 	ZHAOXIN KaiXian KX-U6580@2.5GHz 	3,066 	via
1802 	AMD Opteron 1381 	3,065 	AMD
1803 	AMD Athlon X3 450 	3,064 	AMD
1804 	AMD Opteron X2170 APU 	3,059 	AMD
1805 	Intel Core m3-6Y30 @ 0.90GHz 	3,051 	intel
1806 	Intel Core i3-4120U @ 2.00GHz 	3,050 	intel
1807 	AMD PRO A6-8570 	3,049 	AMD
1808 	Intel Core i5-L16G7 @ 1.40GHz 	3,049 	intel
1809 	Intel Xeon E5606 @ 2.13GHz 	3,049 	intel
1810 	Intel Core i3-5010U @ 2.10GHz 	3,048 	intel
1811 	Intel Core i3-5015U @ 2.10GHz 	3,042 	intel
1812 	Intel Celeron G3930 @ 2.90GHz 	3,040 	intel
1813 	Intel Xeon L5408 @ 2.13GHz 	3,037 	intel
1814 	AMD A8-3800 APU 	3,034 	AMD
1815 	Qualcomm Technologies, Inc LAGOON 	3,030 	via
1816 	Intel Core i3-3250T @ 3.00GHz 	3,021 	intel
1817 	Intel Pentium 1403 v2 @ 2.60GHz 	3,018 	intel
1818 	Intel Core M-5Y70 @ 1.10GHz 	3,016 	intel
1819 	AMD Opteron 6128 HE 	3,015 	AMD
1820 	AMD Phenom 9950 Quad-Core 	3,012 	AMD
1821 	Intel Core i7-720QM @ 1.60GHz 	3,012 	intel
1822 	Intel Pentium G3420T @ 2.70GHz 	3,008 	intel
1823 	AMD A8-5550M APU 	3,006 	AMD
1824 	Intel Celeron G3950 @ 3.00GHz 	3,006 	intel
1825 	SMDK4x12 	3,006 	via
1826 	AMD Phenom 2 X4 12000 	3,005 	AMD
1827 	MediaTek MT6785V/CC 	3,001 	via
1828 	AMD Athlon II X4 655 	2,998 	AMD
1829 	AMD A6-9500 	2,996 	AMD
1830 	Hisilicon Kirin810 	2,996 	via
1831 	AMD Phenom II X3 740 	2,994 	AMD
1832 	AMD Phenom II X4 805 	2,994 	AMD
1833 	Intel Core M-5Y71 @ 1.20GHz 	2,991 	intel
1834 	AMD Phenom 7950 Quad-Core 	2,991 	AMD
1835 	AMD PRO A6-8550B 	2,985 	AMD
1836 	Qualcomm Technologies, Inc SDMMAGPIEP 	2,985 	via
1837 	Intel Core2 Quad Q8300 @ 2.50GHz 	2,985 	intel
1838 	Intel Xeon X6550 @ 2.00GHz 	2,977 	intel
1839 	Intel Xeon E5506 @ 2.13GHz 	2,977 	intel
1840 	Qualcomm Technologies, Inc LITO 	2,973 	via
1841 	Intel Celeron G3930TE @ 2.70GHz 	2,970 	intel
1842 	Intel Pentium G3250T @ 2.80GHz 	2,969 	intel
1843 	Intel Pentium G3450T @ 2.90GHz 	2,967 	intel
1844 	Intel Core i5-4302Y @ 1.60GHz 	2,967 	intel
1845 	MT6785 	2,965 	via
1846 	AMD A8-5557M APU 	2,963 	AMD
1847 	Intel Celeron G4900T @ 2.90GHz 	2,960 	intel
1848 	Intel Core2 Quad Q6600 @ 2.40GHz 	2,954 	intel
1849 	AMD Opteron 2374 HE 	2,951 	AMD
1850 	MT6853V/NZA 	2,951 	via
1851 	AMD Phenom FX-5200 Quad-Core 	2,948 	AMD
1852 	Intel Core i3-560 @ 3.33GHz 	2,943 	intel
1853 	AMD Opteron 4122 	2,942 	AMD
1854 	AMD Opteron 3250 HE 	2,942 	AMD
1855 	Intel Core i3-2100T @ 2.50GHz 	2,941 	intel
1856 	AMD Opteron 6134 	2,938 	AMD
1857 	AMD Athlon II X4 620 	2,937 	AMD
1858 	Intel Pentium G3260T @ 2.90GHz 	2,930 	intel
1859 	Intel Core i5-3439Y @ 1.50GHz 	2,930 	intel
1860 	AMD Phenom II X3 B75 	2,929 	AMD
1861 	Intel Pentium 4405U @ 2.10GHz 	2,929 	intel
1862 	AMD Opteron 2419 EE 	2,926 	AMD
1863 	Six-Core AMD Opteron 2419 EE 	2,925 	AMD
1864 	Intel Xeon E5345 @ 2.33GHz 	2,923 	intel
1865 	Intel Celeron G3900T @ 2.60GHz 	2,919 	intel
1866 	Intel Core i3-4158U @ 2.00GHz 	2,914 	intel
1867 	Intel Celeron J4125 @ 2.00GHz 	2,912 	intel
1868 	Intel Core i7-2637M @ 1.70GHz 	2,909 	intel
1869 	Intel Celeron G1850 @ 2.90GHz 	2,907 	intel
1870 	AMD A10-4657M APU 	2,906 	AMD
1871 	AMD A10-7300 APU 	2,906 	AMD
1872 	AMD Athlon II X4 620e 	2,906 	AMD
1873 	Intel Core i3-4110U @ 1.90GHz 	2,902 	intel
1874 	Intel Core i3-5005U @ 2.00GHz 	2,902 	intel
1875 	Intel Pentium Silver J5005 @ 1.50GHz 	2,902 	intel
1876 	Intel Core i5-4230U @ 1.90GHz 	2,902 	intel
1877 	AMD Athlon II X4 615e 	2,901 	AMD
1878 	AMD Athlon 5370 APU 	2,898 	AMD
1879 	AMD Phenom 9850 Quad-Core 	2,893 	AMD
1880 	AMD Athlon X4 635 	2,891 	AMD
1881 	AMD A6-9500E 	2,889 	AMD
1882 	Intel Pentium G4400TE @ 2.40GHz 	2,885 	intel
1883 	MediaTek MT6785V/CD 	2,884 	via
1884 	AMD Phenom II X4 900e 	2,882 	AMD
1885 	Intel Pentium G3240T @ 2.70GHz 	2,874 	intel
1886 	Intel Pentium G2030 @ 3.00GHz 	2,869 	intel
1887 	Intel Celeron G5905 @ 3.50GHz 	2,862 	intel
1888 	AMD Athlon X4 620 	2,861 	AMD
1889 	Intel Celeron G1840 @ 2.80GHz 	2,860 	intel
1890 	AMD Athlon II X3 460 	2,859 	AMD
1891 	Qualcomm Technologies, Inc SDM720G 	2,852 	via
1892 	Intel Xeon E5405 @ 2.00GHz 	2,850 	intel
1893 	Qualcomm Technologies, Inc SDM730G AIE 	2,843 	via
1894 	Intel Celeron G5920 @ 3.50GHz 	2,840 	intel
1895 	Intel Core i3-2310E @ 2.10GHz 	2,839 	intel
1896 	Celeron Dual-Core Q8300 @ 2.50GHz 	2,837 	via
1897 	Intel Core i7-640M @ 2.80GHz 	2,832 	intel
1898 	Intel Celeron G5925 @ 3.60GHz 	2,830 	intel
1899 	Intel Core i7-2677M @ 1.80GHz 	2,828 	intel
1900 	Intel Core i3-550 @ 3.20GHz 	2,827 	intel
1901 	Intel Pentium G870 @ 3.10GHz 	2,826 	intel
1902 	AMD PRO A6-8570E 	2,824 	AMD
1903 	AMD Opteron 2350 	2,820 	AMD
1904 	Qualcomm Technologies, Inc SDM765G 5G 	2,819 	via
1905 	Intel Core i7-2617M @ 1.50GHz 	2,818 	intel
1906 	Intel Celeron J4115 @ 1.80GHz 	2,816 	intel
1907 	Intel Core M-5Y10c @ 0.80GHz 	2,815 	intel
1908 	AMD Opteron 2356 	2,814 	AMD
1909 	AMD Phenom 9750 Quad-Core 	2,812 	AMD
1910 	Intel Core2 Quad Q8200 @ 2.33GHz 	2,812 	intel
1911 	AMD Phenom X4 Quad-Core GP-9730 	2,812 	AMD
1912 	Intel Core i5-4422E @ 1.80GHz 	2,806 	intel
1913 	AMD A8-7100 APU 	2,804 	AMD
1914 	Intel Pentium G2100T @ 2.60GHz 	2,802 	intel
1915 	AMD A6-3620 APU 	2,799 	AMD
1916 	AMD Athlon II X4 610e 	2,797 	AMD
1917 	AMD A4 PRO-7350B 	2,794 	AMD
1918 	AMD PRO A4-8350B 	2,791 	AMD
1919 	AMD Opteron 2373 EE 	2,789 	AMD
1920 	AMD A6-7400K APU 	2,783 	AMD
1921 	Intel Core i3-4025U @ 1.90GHz 	2,782 	intel
1922 	AMD Phenom II X4 B05e 	2,781 	AMD
1923 	Intel Core i3-2370M @ 2.40GHz 	2,776 	intel
1924 	Qualcomm Technologies, Inc SDMMAGPIE 	2,773 	via
1925 	Qualcomm Technologies, Inc SM7125 	2,770 	via
1926 	AMD Athlon II X3 455 	2,769 	AMD
1927 	Intel E3000 @ 3.40GHz 	2,767 	intel
1928 	Intel Celeron G3930T @ 2.70GHz 	2,766 	intel
1929 	AMD Opteron 1356 	2,765 	AMD
1930 	AMD A10-5745M APU 	2,762 	AMD
1931 	Intel Pentium G2020 @ 2.90GHz 	2,762 	intel
1932 	AMD PRO A6-9500E 	2,761 	AMD
1933 	AMD PRO A6-7350B 	2,759 	AMD
1934 	Intel Celeron G1820 @ 2.70GHz 	2,757 	intel
1935 	Intel Xeon L5335 @ 2.00GHz 	2,756 	intel
1936 	AMD RX-425BB 	2,756 	AMD
1937 	AMD Athlon II X4 605e 	2,750 	AMD
1938 	AMD 3020e 	2,748 	AMD
1939 	Intel Pentium 1403 @ 2.60GHz 	2,742 	intel
1940 	Intel Pentium G860 @ 3.00GHz 	2,741 	intel
1941 	AMD A8-7410 APU 	2,738 	AMD
1942 	Intel Xeon X3210 @ 2.13GHz 	2,737 	intel
1943 	Intel Celeron G5900 @ 3.40GHz 	2,737 	intel
1944 	AMD Phenom II X4 B15e 	2,736 	AMD
1945 	AMD Phenom II X3 B73 	2,735 	AMD
1946 	AMD A6-7470K 	2,727 	AMD
1947 	Intel Core i7-620M @ 2.67GHz 	2,723 	intel
1948 	Intel Core M-5Y10 @ 0.80GHz 	2,722 	intel
1949 	AMD A6-9400 	2,717 	AMD
1950 	AMD Phenom X4 Quad-Core GP-9830 	2,715 	AMD
1951 	Intel Celeron G4950 @ 3.30GHz 	2,714 	intel
1952 	AMD Phenom 9750B Quad-Core 	2,709 	AMD
1953 	AMD A9-9425 	2,708 	AMD
1954 	Intel Core i3-4030U @ 1.90GHz 	2,706 	intel
1955 	AMD A6-3600 APU 	2,703 	AMD
1956 	Intel Xeon E5504 @ 2.00GHz 	2,702 	intel
1957 	AMD Phenom II X940 Quad-Core 	2,695 	AMD
1958 	AMD A6 PRO-7400B 	2,690 	AMD
1959 	AMD Phenom X4 Quad-Core GP-9930 	2,690 	AMD
1960 	Intel Core i3-540 @ 3.07GHz 	2,687 	intel
1961 	Intel Celeron G3900E @ 2.40GHz 	2,679 	intel
1962 	AMD Phenom II X3 720 	2,679 	AMD
1963 	AMD 3015e 	2,678 	AMD
1964 	AMD Opteron 3320 EE 	2,675 	AMD
1965 	Intel Core i5-2557M @ 1.70GHz 	2,671 	intel
1966 	Intel Core i5-6442EQ @ 1.90GHz 	2,670 	intel
1967 	AMD A8-4500M APU 	2,666 	AMD
1968 	AMD Athlon Silver 3050e 	2,664 	AMD
1969 	Intel Pentium G850 @ 2.90GHz 	2,662 	intel
1970 	AMD A6-7310 APU 	2,659 	AMD
1971 	Qualcomm Technologies, Inc SM6150 	2,656 	via
1972 	Intel Core i5 650 @ 3.20GHz 	2,653 	intel
1973 	AMD Phenom II N830 3+1 	2,652 	AMD
1974 	AMD A8 PRO-7150B APU 	2,650 	AMD
1975 	AMD Phenom II X3 715 	2,649 	AMD
1976 	Intel Core M-5Y31 @ 0.90GHz 	2,648 	intel
1977 	Samsung Exynos 8895 	2,643 	via
1978 	Intel Celeron J4105 @ 1.50GHz 	2,641 	intel
1979 	AMD Opteron 2380 	2,640 	AMD
1980 	AMD Phenom II X920 Quad-Core 	2,640 	AMD
1981 	AMD Phenom 9650 Quad-Core 	2,638 	AMD
1982 	AMD Opteron 1354 	2,630 	AMD
1983 	AMD Athlon II X3 450 	2,623 	AMD
1984 	Intel Core i5-580M @ 2.67GHz 	2,623 	intel
1985 	Intel Core i3-2348M @ 2.30GHz 	2,621 	intel
1986 	AMD Phenom 9450e Quad-Core 	2,621 	AMD
1987 	Intel Core i3-2350M @ 2.30GHz 	2,619 	intel
1988 	AMD A6-6420B APU 	2,612 	AMD
1989 	AMD A8-3550MX APU 	2,610 	AMD
1990 	Intel Celeron G1840T @ 2.50GHz 	2,605 	intel
1991 	AMD Athlon 5350 APU 	2,605 	AMD
1992 	AMD A10-4655M APU 	2,603 	AMD
1993 	AMD Athlon II X4 6400e 	2,594 	AMD
1994 	Intel Pentium G2010 @ 2.80GHz 	2,593 	intel
1995 	Intel Celeron G3900TE @ 2.30GHz 	2,591 	intel
1996 	Intel Core i5-560M @ 2.67GHz 	2,588 	intel
1997 	Intel Pentium G645 @ 2.90GHz 	2,585 	intel
1998 	AMD A8-5545M APU 	2,585 	AMD
1999 	Intel Core i7-2630UM @ 1.60GHz 	2,584 	intel
2000 	Intel Celeron G1620 @ 2.70GHz 	2,582 	intel
2001 	AMD Phenom 9600B Quad-Core 	2,577 	AMD
2002 	AMD Athlon X3 435 	2,574 	AMD
2003 	AMD Athlon II X3 445 	2,573 	AMD
2004 	AMD A9-9430 	2,573 	AMD
2005 	AMD A8-6410 APU 	2,572 	AMD
2006 	AMD Athlon II X3 440 	2,571 	AMD
2007 	MediaTek MT6779V/CE 	2,570 	via
2008 	Intel Pentium G3220T @ 2.60GHz 	2,567 	intel
2009 	AMD Athlon II X4 557 	2,567 	AMD
2010 	Intel Core i3-530 @ 2.93GHz 	2,566 	intel
2011 	Intel Pentium G840 @ 2.80GHz 	2,562 	intel
2012 	Intel Pentium 6405U @ 2.40GHz 	2,561 	intel
2013 	MediaTek MT6779V/CV 	2,561 	via
2014 	AMD A9-9410 	2,557 	AMD
2015 	AMD A4-6250J APU 	2,556 	AMD
2016 	Intel Core m3-7Y32 @ 1.10GHz 	2,555 	intel
2017 	Intel Celeron 4305UE @ 2.00GHz 	2,554 	intel
2018 	Intel Celeron G1830 @ 2.80GHz 	2,544 	intel
2019 	Intel Core i7-610E @ 2.53GHz 	2,544 	intel
2020 	AMD Phenom 9550 Quad-Core 	2,543 	AMD
2021 	Intel Atom C3558 @ 2.20GHz 	2,538 	intel
2022 	Intel Xeon X5270 @ 3.50GHz 	2,535 	intel
2023 	Intel Core i3-2328M @ 2.20GHz 	2,533 	intel
2024 	Intel Pentium G640 @ 2.80GHz 	2,531 	intel
2025 	Intel Core2 Quad Q9000 @ 2.00GHz 	2,528 	intel
2026 	Intel Pentium 3825U @ 1.90GHz 	2,527 	intel
2027 	AMD Phenom II N970 Quad-Core 	2,524 	AMD
2028 	Intel Core i3-2330M @ 2.20GHz 	2,522 	intel
2029 	AMD PRO A4-3350B APU 	2,518 	AMD
2030 	AMD Phenom FX-5000 Quad-Core 	2,517 	AMD
2031 	AMD PRO A6-8500B 	2,516 	AMD
2032 	Snapdragon 7c Gen 2 @ 2.55 	2,515 	via
2033 	Intel Xeon E5335 @ 2.00GHz 	2,513 	intel
2034 	MediaTek MT6779V/CU 	2,512 	via
2035 	Intel Pentium G2030T @ 2.60GHz 	2,510 	intel
2036 	AMD Embedded G-Series GX-420GI Radeon R7E 	2,509 	AMD
2037 	Intel Core i3-4030Y @ 1.60GHz 	2,507 	intel
2038 	AMD A4-7210 APU 	2,507 	AMD
2039 	AMD Athlon X4 605e 	2,505 	AMD
2040 	Intel Celeron G1820T @ 2.40GHz 	2,505 	intel
2041 	Pentium Dual-Core E6000 @ 3.46GHz 	2,501 	via
2042 	Qualcomm Technologies, Inc MSM8998 	2,495 	via
2043 	Intel Celeron G1630 @ 2.80GHz 	2,493 	intel
2044 	Intel Celeron G1610 @ 2.60GHz 	2,490 	intel
2045 	AMD GX-424CC SOC 	2,488 	AMD
2046 	Apple A9X 	2,486 	via
2047 	Intel Core i5 E 520 @ 2.40GHz 	2,486 	intel
2048 	AMD Phenom II N950 Quad-Core 	2,484 	AMD
2049 	Intel Core i5-4300Y @ 1.60GHz 	2,484 	intel
2050 	Intel Core i7-2610UE @ 1.50GHz 	2,481 	intel
2051 	Intel Core M-5Y51 @ 1.10GHz 	2,477 	intel
2052 	AMD Athlon II X3 435 	2,474 	AMD
2053 	Intel Pentium G2020T @ 2.50GHz 	2,466 	intel
2054 	Intel Core i3-3227U @ 1.90GHz 	2,466 	intel
2055 	Intel Pentium Silver N5000 @ 1.10GHz 	2,463 	intel
2056 	Intel Celeron J3455E @ 1.50GHz 	2,457 	intel
2057 	HiSilicon Kirin 970 	2,455 	via
2058 	Intel Atom C3538 @ 2.10GHz 	2,455 	intel
2059 	AMD Athlon II X4 600e 	2,453 	AMD
2060 	Intel Xeon X5260 @ 3.33GHz 	2,453 	intel
2061 	AMD Opteron 2354 	2,450 	AMD
2062 	Intel Core i5-540M @ 2.53GHz 	2,449 	intel
2063 	Intel Core i3-4005U @ 1.70GHz 	2,446 	intel
2064 	AMD A6-6310 APU 	2,445 	AMD
2065 	AMD Phenom II X3 710 	2,443 	AMD
2066 	Intel Core i3-4010U @ 1.70GHz 	2,436 	intel
2067 	Qualcomm Technologies, Inc SM7150 	2,434 	via
2068 	Intel Core i3-2310M @ 2.10GHz 	2,428 	intel
2069 	Intel Xeon E3113 @ 3.00GHz 	2,427 	intel
2070 	AMD A6-5200 APU 	2,424 	AMD
2071 	Intel Xeon E5240 @ 3.00GHz 	2,424 	intel
2072 	Intel Celeron G555 @ 2.70GHz 	2,422 	intel
2073 	Intel Pentium 2030M @ 2.50GHz 	2,417 	intel
2074 	Intel Xeon E7320 @ 2.13GHz 	2,413 	intel
2075 	Intel Celeron G5905T @ 3.30GHz 	2,412 	intel
2076 	Intel Celeron 3965U @ 2.20GHz 	2,411 	intel
2077 	AMD Embedded R-Series RX-216GD 	2,409 	AMD
2078 	Intel Core2 Duo E8600 @ 3.33GHz 	2,408 	intel
2079 	Intel Core i5-4200Y @ 1.40GHz 	2,407 	intel
2080 	Intel Core i5-480M @ 2.67GHz 	2,405 	intel
2081 	Apple A8X 	2,404 	via
2082 	AMD A4 PRO-3340B 	2,402 	AMD
2083 	AMD Athlon X3 455 	2,401 	AMD
2084 	HiSilicon Kirin 960 	2,398 	via
2085 	Intel Xeon X5272 @ 3.40GHz 	2,394 	intel
2086 	Intel Pentium G3320TE @ 2.30GHz 	2,389 	intel
2087 	AMD PRO A6-8530B 	2,388 	AMD
2088 	Intel Core M-5Y10a @ 0.80GHz 	2,387 	intel
2089 	Intel Core i3-2332M @ 2.20GHz 	2,382 	intel
2090 	Intel Core i3-2312M @ 2.10GHz 	2,381 	intel
2091 	Intel Core i5-4210Y @ 1.50GHz 	2,380 	intel
2092 	AMD Phenom II X4 8700e 	2,377 	AMD
2093 	Qualcomm Technologies, Inc ATOLL-AB 	2,375 	via
2094 	AMD A8-3530MX APU 	2,375 	AMD
2095 	Intel Pentium G630 @ 2.70GHz 	2,372 	intel
2096 	AMD A8-3510MX APU 	2,370 	AMD
2097 	Intel Core i5-520M @ 2.40GHz 	2,370 	intel
2098 	AMD Opteron X3216 APU 	2,368 	AMD
2099 	Intel Xeon E5603 @ 1.60GHz 	2,366 	intel
2100 	Intel Celeron 2000E @ 2.20GHz 	2,365 	intel
2101 	AMD GX-420CA SOC 	2,362 	AMD
2102 	AMD A6-6420K APU 	2,361 	AMD
2103 	Intel Core2 Duo E8290 @ 2.83GHz 	2,353 	intel
2104 	Intel Celeron G1620T @ 2.40GHz 	2,353 	intel
2105 	MT6771V/WL 	2,352 	via
2106 	Snapdragon 7c @ 2.40 GHz 	2,349 	via
2107 	AMD A4 PRO-7300B APU 	2,338 	AMD
2108 	Intel Core i5-2467M @ 1.60GHz 	2,335 	intel
2109 	AMD A4-6320 APU 	2,329 	AMD
2110 	Intel Atom C2550 @ 2.40GHz 	2,329 	intel
2111 	Intel Core i5-460M @ 2.53GHz 	2,325 	intel
2112 	AMD Phenom 9350e Quad-Core 	2,320 	AMD
2113 	AMD Opteron 1352 	2,316 	AMD
2114 	AMD A9-9420 	2,315 	AMD
2115 	AMD Athlon X3 445 	2,314 	AMD
2116 	Intel Celeron N4100 @ 1.10GHz 	2,314 	intel
2117 	AMD Athlon II X3 425 	2,313 	AMD
2118 	Intel Celeron 2970M @ 2.20GHz 	2,312 	intel
2119 	AMD Phenom 9600 Quad-Core 	2,304 	AMD
2120 	Intel Pentium 3550M @ 2.30GHz 	2,304 	intel
2121 	Intel Core i3-3217U @ 1.80GHz 	2,303 	intel
2122 	AMD Athlon X2 280 	2,303 	AMD
2123 	AMD A6-6400K APU 	2,303 	AMD
2124 	Intel Celeron G1610T @ 2.30GHz 	2,303 	intel
2125 	Intel Pentium J4205 @ 1.50GHz 	2,300 	intel
2126 	AMD A9-9400 	2,300 	AMD
2127 	AMD A4-7300 APU 	2,298 	AMD
2128 	AMD A6-9225 	2,294 	AMD
2129 	Intel Pentium G620 @ 2.60GHz 	2,293 	intel
2130 	Intel Pentium G645T @ 2.50GHz 	2,289 	intel
2131 	Intel Xeon E5320 @ 1.86GHz 	2,288 	intel
2132 	AMD Athlon II X3 420e 	2,285 	AMD
2133 	Intel Celeron G550 @ 2.60GHz 	2,285 	intel
2134 	AMD Phenom II X3 700e 	2,285 	AMD
2135 	AMD Opteron 2376 	2,283 	AMD
2136 	Intel Core2 Duo E8500 @ 3.16GHz 	2,282 	intel
2137 	AMD A6-6400B APU 	2,281 	AMD
2138 	AMD E2-7110 APU 	2,281 	AMD
2139 	Intel Pentium 2020M @ 2.40GHz 	2,278 	intel
2140 	Intel Pentium Silver N5030 @ 1.10GHz 	2,276 	intel
2141 	Intel Xeon L5310 @ 1.60GHz 	2,274 	intel
2142 	Intel Xeon L3110 @ 3.00GHz 	2,273 	intel
2143 	Intel Xeon L5240 @ 3.00GHz 	2,271 	intel
2144 	AMD Phenom II N930 Quad-Core 	2,270 	AMD
2145 	Qualcomm Technologies, Inc SM4350 	2,267 	via
2146 	Intel Core i7-640LM @ 2.13GHz 	2,265 	intel
2147 	Intel Xeon E5310 @ 1.60GHz 	2,264 	intel
2148 	MediaTek MT6771V/C 	2,263 	via
2149 	Snapdragon 850 @ 2.96 GHz 	2,263 	via
2150 	Intel Core i5-4220Y @ 1.60GHz 	2,262 	intel
2151 	MediaTek MT6769T 	2,259 	via
2152 	AArch64 rev 1 (aarch64) 	2,258 	via
2153 	Intel Core i5-4202Y @ 1.60GHz 	2,256 	intel
2154 	AMD Opteron 8354 	2,255 	AMD
2155 	MediaTek MT6771V/W 	2,253 	via
2156 	MediaTek MT6769V/CB 	2,251 	via
2157 	AMD Athlon X2 370K Dual Core 	2,251 	AMD
2158 	Intel Celeron 6305 @ 1.80GHz 	2,251 	intel
2159 	AMD Athlon II X3 415e 	2,247 	AMD
2160 	AMD Opteron 2393 SE 	2,246 	AMD
2161 	Intel Core i5-520 @ 2.40GHz 	2,244 	intel
2162 	Intel Xeon E3120 @ 3.16GHz 	2,241 	intel
2163 	Intel Pentium 3560M @ 2.40GHz 	2,240 	intel
2164 	AMD Athlon II X3 425e 	2,239 	AMD
2165 	AMD Phenom X4 Quad-Core GP-9600 	2,235 	AMD
2166 	Intel Celeron 1020E @ 2.20GHz 	2,232 	intel
2167 	AMD A6-3430MX APU 	2,229 	AMD
2168 	MT6969T 	2,228 	via
2169 	AMD Phenom II X3 705e 	2,227 	AMD
2170 	Hisilicon Kirin820 	2,226 	via
2171 	AMD A4-6300 APU 	2,224 	AMD
2172 	Intel Xeon D-1602 @ 2.50GHz 	2,219 	intel
2173 	Qualcomm Technologies, Inc SDM660 	2,218 	via
2174 	Qualcomm Technologies, Inc SM6125 	2,214 	via
2175 	Intel Core i3-4020Y @ 1.50GHz 	2,213 	intel
2176 	Intel Core2 Duo E8700 @ 3.50GHz 	2,212 	intel
2177 	AMD Phenom II X2 565 	2,211 	AMD
2178 	MediaTek MT6769V/CU 	2,210 	via
2179 	Intel Celeron N6211 @ 1.20GHz 	2,207 	intel
2180 	AMD Phenom X2 Dual-Core GE-5560 	2,206 	AMD
2181 	Intel Celeron G540 @ 2.50GHz 	2,205 	intel
2182 	Intel Pentium 4415Y @ 1.60GHz 	2,205 	intel
2183 	Qualcomm Technologies, Inc SDA660 	2,204 	via
2184 	AMD Phenom 9500 Quad-Core 	2,204 	AMD
2185 	Qualcomm Technologies, Inc BENGAL 	2,203 	via
2186 	Intel Core i5-3339Y @ 1.50GHz 	2,203 	intel
2187 	AMD A6-8500P 	2,202 	AMD
2188 	Qualcomm Technologies, Inc BENGALP 	2,202 	via
2189 	Qualcomm Technologies, Inc SDM710 	2,200 	via
2190 	MT6769V/CT 	2,200 	via
2191 	AMD A6-5400B APU 	2,199 	AMD
2192 	Intel Core i5 750S @ 2.40GHz 	2,197 	intel
2193 	Samsung Exynos 8890 	2,194 	via
2194 	MediaTek MT6769V/WB 	2,192 	via
2195 	AMD Athlon X3 425 	2,191 	AMD
2196 	AMD A6-9220 	2,190 	AMD
2197 	AMD Phenom II X620 Dual-Core 	2,189 	AMD
2198 	AMD Opteron 1389 	2,183 	AMD
2199 	Intel Core i3-390M @ 2.67GHz 	2,180 	intel
2200 	AMD A8-3520M APU 	2,178 	AMD
2201 	HP Hexa-Core 2.0GHz 	2,178 	via
2202 	Intel Atom C2558 @ 2.40GHz 	2,169 	intel
2203 	MT6769V/CZ 	2,168 	via
2204 	Intel Xeon E3110 @ 3.00GHz 	2,165 	intel
2205 	Intel Core i3-3217UE @ 1.60GHz 	2,162 	intel
2206 	Rockchip RK3399 	2,162 	via
2207 	MediaTek MT6771V/CT 	2,159 	via
2208 	Qualcomm Technologies, Inc SDM670 	2,159 	via
2209 	Intel Core i3-4012Y @ 1.50GHz 	2,158 	intel
2210 	AMD A4-6210 APU 	2,155 	AMD
2211 	AMD Opteron 6378 	2,152 	AMD
2212 	Intel Core2 Duo E8400 @ 3.00GHz 	2,151 	intel
2213 	AMD A6-5400K APU 	2,149 	AMD
2214 	Intel Celeron J3455 @ 1.50GHz 	2,147 	intel
2215 	AMD A6-9220C 	2,147 	AMD
2216 	Hisilicon Kirin970 	2,144 	via
2217 	MediaTek MT6769Z 	2,144 	via
2218 	Intel Pentium G6951 @ 2.80GHz 	2,140 	intel
2219 	Intel Celeron G530 @ 2.40GHz 	2,139 	intel
2220 	AMD Phenom II X2 B59 	2,139 	AMD
2221 	Intel Xeon L5320 @ 1.86GHz 	2,135 	intel
2222 	Intel Celeron G1820TE @ 2.20GHz 	2,132 	intel
2223 	AMD Athlon II X2 280 	2,131 	AMD
2224 	Intel Core2 Duo T9900 @ 3.06GHz 	2,130 	intel
2225 	AMD A4-6300B APU 	2,129 	AMD
2226 	Intel Core2 Duo E8335 @ 2.93GHz 	2,128 	intel
2227 	Intel Core2 Duo E8435 @ 3.06GHz 	2,127 	intel
2228 	AMD A4-5300B APU 	2,125 	AMD
2229 	AMD A8-4555M APU 	2,125 	AMD
2230 	Hisilicon Kirin710 	2,123 	via
2231 	Intel Celeron G4930T @ 3.00GHz 	2,117 	intel
2232 	Intel Core i5-450M @ 2.40GHz 	2,117 	intel
2233 	Intel Celeron G540T @ 2.10GHz 	2,114 	intel
2234 	Apple A9 	2,113 	via
2235 	AMD A4-5050 APU 	2,113 	AMD
2236 	AMD Phenom 9150e Quad-Core 	2,113 	AMD
2237 	AMD Sempron 240 	2,110 	AMD
2238 	Intel Xeon E3-1220L v3 @ 1.10GHz 	2,110 	intel
2239 	AMD Phenom II X2 511 	2,104 	AMD
2240 	AMD Athlon 5150 APU 	2,103 	AMD
2241 	AMD A6-9230 	2,102 	AMD
2242 	Intel Core i5-430M @ 2.27GHz 	2,100 	intel
2243 	Intel Pentium A1020 @ 2.41GHz 	2,096 	intel
2244 	Intel Core i5-2537M @ 1.40GHz 	2,095 	intel
2245 	Intel Core i3-380M @ 2.53GHz 	2,094 	intel
2246 	Intel Pentium G630T @ 2.30GHz 	2,089 	intel
2247 	Qualcomm Technologies, Inc SDM712 	2,089 	via
2248 	AMD Embedded G-Series GX-224IJ Radeon R4E 	2,088 	AMD
2249 	AMD Phenom II P960 Quad-Core 	2,086 	AMD
2250 	Intel Atom C2538 @ 2.40GHz 	2,085 	intel
2251 	AMD Athlon II X2 B28 	2,083 	AMD
2252 	Intel Pentium G6960 @ 2.93GHz 	2,083 	intel
2253 	AMD Phenom 8850B Triple-Core 	2,080 	AMD
2254 	Unisoc T618 	2,080 	via
2255 	AMD Athlon X3 440 	2,078 	AMD
2256 	AMD Phenom II X2 521 	2,077 	AMD
2257 	AMD PRO A6-9500B 	2,076 	AMD
2258 	MediaTek MT6771V/WM 	2,073 	via
2259 	ZHAOXIN KaiXian ZX-C+ C4700@2.0GHz 	2,069 	via
2260 	MediaTek MT6768V/CA 	2,065 	via
2261 	Unisoc ums512 	2,065 	via
2262 	Intel Celeron G550T @ 2.20GHz 	2,063 	intel
2263 	HiSilicon Kirin 950 	2,061 	via
2264 	Intel Core2 Extreme X9100 @ 3.06GHz 	2,061 	intel
2265 	Intel Pentium 4405Y @ 1.50GHz 	2,059 	intel
2266 	AMD Phenom 8750 Triple-Core 	2,058 	AMD
2267 	AMD Phenom II X2 560 	2,057 	AMD
2268 	AArch64 rev 2 (aarch64) 	2,053 	via
2269 	AMD A6-3410MX APU 	2,052 	AMD
2270 	MediaTek MT6763V/CE 	2,049 	via
2271 	Intel Pentium 4410Y @ 1.50GHz 	2,047 	intel
2272 	AMD Phenom II X2 555 	2,044 	AMD
2273 	AMD Phenom 8450e Triple-Core 	2,040 	AMD
2274 	Intel Atom T5700 @ 1.70GHz 	2,039 	intel
2275 	AMD A4-5100 APU 	2,037 	AMD
2276 	AMD Phenom 8750B Triple-Core 	2,034 	AMD
2277 	Intel Pentium B980 @ 2.40GHz 	2,034 	intel
2278 	Intel Pentium G620T @ 2.20GHz 	2,028 	intel
2279 	AMD Phenom 8850 Triple-Core 	2,026 	AMD
2280 	AMD Athlon II X3 405e 	2,025 	AMD
2281 	Intel Celeron 1020M @ 2.10GHz 	2,023 	intel
2282 	AMD Phenom II X2 550 	2,021 	AMD
2283 	MT6797M 	2,021 	via
2284 	AMD Phenom II X640 Dual-Core 	2,021 	AMD
2285 	Intel Core i3-370M @ 2.40GHz 	2,017 	intel
2286 	Qualcomm Technologies, Inc TRINKET 	2,015 	via
2287 	Samsung Exynos 9611 	2,014 	via
2288 	Intel Pentium N4200 @ 1.10GHz 	2,013 	intel
2289 	Intel Core2 Duo T9800 @ 2.93GHz 	2,013 	intel
2290 	Intel Core2 Duo P9700 @ 2.80GHz 	2,012 	intel
2291 	AMD A4-5300 APU 	2,011 	AMD
2292 	AMD A6-3500 APU 	2,011 	AMD
2293 	Intel Celeron 3867U @ 1.80GHz 	2,010 	intel
2294 	AMD Athlon II X3 400e 	2,009 	AMD
2295 	AMD R-272F APU 	2,007 	AMD
2296 	AMD A4-9125 	2,004 	AMD
2297 	AMD A6-3420M APU 	2,002 	AMD
2298 	Qualcomm Technologies, Inc SDM665 	2,001 	via
2299 	Intel Celeron 2950M @ 2.00GHz 	1,997 	intel
2300 	AMD Phenom X4 Quad-Core GP-9530 	1,994 	AMD
2301 	AMD Opteron 1385 	1,993 	AMD
2302 	Intel Core2 Duo E8300 @ 2.83GHz 	1,992 	intel
2303 	AMD Phenom 8650 Triple-Core 	1,991 	AMD
2304 	Intel Celeron 3765U @ 1.90GHz 	1,990 	intel
2305 	AMD Phenom II N870 Triple-Core 	1,988 	AMD
2306 	AMD A8-7050 	1,986 	AMD
2307 	Intel Pentium 3805U @ 1.90GHz 	1,981 	intel
2308 	AMD Athlon II X2 270 	1,979 	AMD
2309 	Intel Pentium E6800 @ 3.33GHz 	1,977 	intel
2310 	Intel Core2 Duo E7600 @ 3.06GHz 	1,973 	intel
2311 	ARM Neoverse-N1 2 Core 0 MHz 	1,971 	via
2312 	AMD A8-3500M APU 	1,971 	AMD
2313 	Intel Core i7-610 @ 2.53GHz 	1,969 	intel
2314 	Intel Celeron N4500 @ 1.10GHz 	1,967 	intel
2315 	Intel Core2 Duo E8235 @ 2.80GHz 	1,965 	intel
2316 	Intel Xeon 5160 @ 3.00GHz 	1,964 	intel
2317 	Intel Pentium J2900 @ 2.41GHz 	1,960 	intel
2318 	AMD Phenom II X2 570 	1,960 	AMD
2319 	Intel Pentium B970 @ 2.30GHz 	1,959 	intel
2320 	AMD R-460L APU 	1,954 	AMD
2321 	Intel Core i7-620LM @ 2.00GHz 	1,954 	intel
2322 	Intel Atom E3900 @ 1.60GHz 	1,953 	intel
2323 	Intel Celeron 4205U @ 1.80GHz 	1,953 	intel
2324 	AMD Athlon II X2 250e 	1,949 	AMD
2325 	Intel Core2 Duo E6850 @ 3.00GHz 	1,948 	intel
2326 	AMD GX-415GA SOC 	1,946 	AMD
2327 	Intel Pentium E6700 @ 3.20GHz 	1,942 	intel
2328 	Qualcomm Technologies, Inc SM4250 	1,941 	via
2329 	AMD A6-5357M APU 	1,938 	AMD
2330 	Qualcomm Technologies, Inc SDM636 	1,937 	via
2331 	Intel Celeron 3865U @ 1.80GHz 	1,936 	intel
2332 	Intel Core i3-330E @ 2.13GHz 	1,935 	intel
2333 	AMD Phenom II N850 Triple-Core 	1,935 	AMD
2334 	Intel Pentium J3710 @ 1.60GHz 	1,932 	intel
2335 	AMD Phenom II X2 B55 	1,931 	AMD
2336 	Intel Pentium N3540 @ 2.16GHz 	1,930 	intel
2337 	Intel Core2 Duo T9600 @ 2.80GHz 	1,926 	intel
2338 	AMD Phenom X3 8550 	1,922 	AMD
2339 	AMD Phenom 8600B Triple-Core 	1,920 	AMD
2340 	AMD Opteron 2224 SE 	1,919 	AMD
2341 	Intel Celeron N4120 @ 1.10GHz 	1,919 	intel
2342 	AMD A4-4020 APU 	1,918 	AMD
2343 	AMD A4-9120 	1,915 	AMD
2344 	AArch64 rev 0 (aarch64) 	1,913 	via
2345 	AMD Phenom II X2 545 	1,911 	AMD
2346 	AMD A4-5000 APU 	1,908 	AMD
2347 	AMD A9-9420e 	1,908 	AMD
2348 	Intel Xeon @ 2.20GHz 	1,902 	intel
2349 	Intel Atom x7-Z8750 @ 1.60GHz 	1,901 	intel
2350 	AMD Athlon X2 340 Dual Core 	1,901 	AMD
2351 	AMD E2-6110 APU 	1,901 	AMD
2352 	Intel Atom x7-Z8700 @ 1.60GHz 	1,900 	intel
2353 	Intel Core i3-4010Y @ 1.30GHz 	1,900 	intel
2354 	Intel Core2 Extreme X9000 @ 2.80GHz 	1,900 	intel
2355 	AMD A6-5350M APU 	1,899 	AMD
2356 	Intel Pentium G640T @ 2.40GHz 	1,898 	intel
2357 	MediaTek MT6797 	1,898 	via
2358 	MediaTek MT6771V/WT 	1,897 	via
2359 	VIA QuadCore C4650@2.0GHz 	1,897 	via
2360 	Intel Pentium E5800 @ 3.20GHz 	1,895 	intel
2361 	Intel Core i3-350M @ 2.27GHz 	1,893 	intel
2362 	Intel Pentium N3530 @ 2.16GHz 	1,892 	intel
2363 	AMD Athlon II X2 B26 	1,891 	AMD
2364 	AMD A10 Micro-6700T APU 	1,890 	AMD
2365 	AMD Athlon II X2 265 	1,890 	AMD
2366 	AMD Phenom II N830 Triple-Core 	1,889 	AMD
2367 	Intel Atom E3940 @ 1.60GHz 	1,889 	intel
2368 	Intel Core2 Duo E8200 @ 2.66GHz 	1,888 	intel
2369 	AMD Phenom 8450 Triple-Core 	1,887 	AMD
2370 	AMD A6-3400M APU 	1,885 	AMD
2371 	Intel Core2 Duo P9600 @ 2.66GHz 	1,881 	intel
2372 	Qualcomm Technologies, Inc SDM460 	1,881 	via
2373 	Qualcomm Technologies, Inc SDM632 	1,881 	via
2374 	Intel Core2 Duo E7500 @ 2.93GHz 	1,875 	intel
2375 	Intel Pentium E6600 @ 3.06GHz 	1,872 	intel
2376 	AMD Athlon II X2 260 	1,872 	AMD
2377 	Intel Core2 Extreme X6800 @ 2.93GHz 	1,870 	intel
2378 	AMD Phenom II P920 Quad-Core 	1,866 	AMD
2379 	Intel Pentium N3710 @ 1.60GHz 	1,863 	intel
2380 	Intel Celeron 3955U @ 2.00GHz 	1,862 	intel
2381 	Intel Pentium G6950 @ 2.80GHz 	1,859 	intel
2382 	Intel Xeon W3505 @ 2.53GHz 	1,858 	intel
2383 	AMD Phenom II N660 Dual-Core 	1,853 	AMD
2384 	Intel Pentium B960 @ 2.20GHz 	1,853 	intel
2385 	ARM Cortex-A53 6 Core 1896 MHz 	1,851 	via
2386 	Intel Celeron J1900 @ 1.99GHz 	1,850 	intel
2387 	AMD Athlon II X2 255 	1,846 	AMD
2388 	Intel Core2 Duo E8335 @ 2.66GHz 	1,846 	intel
2389 	AMD A4-5150M APU 	1,844 	AMD
2390 	AMD Opteron 2222 	1,843 	AMD
2391 	Intel Celeron N3450 @ 1.10GHz 	1,843 	intel
2392 	Intel Atom x5-Z8550 @ 1.44GHz 	1,841 	intel
2393 	Intel Xeon 3075 @ 2.66GHz 	1,840 	intel
2394 	Intel Pentium J2850 @ 2.41GHz 	1,839 	intel
2395 	AMD Phenom 9100e Quad-Core 	1,835 	AMD
2396 	AMD A6 Micro-6500T APU 	1,834 	AMD
2397 	Qualcomm Technologies, Inc SDM662 	1,833 	via
2398 	Intel Pentium N3700 @ 1.60GHz 	1,833 	intel
2399 	Intel Atom E3950 @ 1.60GHz 	1,827 	intel
2400 	AMD Phenom II X2 B57 	1,826 	AMD
2401 	Intel Xeon L5238 @ 2.66GHz 	1,823 	intel
2402 	AMD A4-4000 APU 	1,822 	AMD
2403 	Intel Celeron N4020 @ 1.10GHz 	1,820 	intel
2404 	Intel Core i3-2377M @ 1.50GHz 	1,820 	intel
2405 	AMD Phenom II P940 Quad-Core 	1,820 	AMD
2406 	Intel Pentium 2127U @ 1.90GHz 	1,819 	intel
2407 	Intel Celeron 1005M @ 1.90GHz 	1,811 	intel
2408 	AMD Athlon X2 235e 	1,806 	AMD
2409 	Intel Pentium N3520 @ 2.16GHz 	1,803 	intel
2410 	AMD A6-9210 	1,802 	AMD
2411 	Snapdragon 835 	1,802 	via
2412 	Intel Core2 Extreme X7800 @ 2.60GHz 	1,802 	intel
2413 	Intel Core2 Duo T9550 @ 2.66GHz 	1,801 	intel
2414 	AMD GX-420MC SOC 	1,796 	AMD
2415 	Intel Core2 Duo T9500 @ 2.60GHz 	1,796 	intel
2416 	Qualcomm Technologies, Inc APQ8053 	1,796 	via
2417 	AMD Athlon 64 FX-72 	1,794 	AMD
2418 	Intel Core i3-330M @ 2.13GHz 	1,791 	intel
2419 	Intel Celeron J3160 @ 1.60GHz 	1,791 	intel
2420 	AMD Athlon 64 X2 Dual Core 6400+ 	1,791 	AMD
2421 	AMD Athlon X4 530 	1,786 	AMD
2422 	Intel Core i3-2375M @ 1.50GHz 	1,780 	intel
2423 	Intel Core i5 M 540 @ 2.53GHz 	1,776 	intel
2424 	Intel Xeon 3070 @ 2.66GHz 	1,776 	intel
2425 	AMD E2-9010 	1,774 	AMD
2426 	Intel Core2 Duo E7400 @ 2.80GHz 	1,772 	intel
2427 	Intel Atom Z3795 @ 1.60GHz 	1,771 	intel
2428 	AMD Athlon II X2 B24 	1,771 	AMD
2429 	Intel Core2 Duo P9500 @ 2.53GHz 	1,765 	intel
2430 	Intel Pentium E6500 @ 2.93GHz 	1,760 	intel
2431 	AMD Phenom II P860 Triple-Core 	1,759 	AMD
2432 	AMD Opteron 1222 	1,757 	AMD
2433 	Intel Xeon W3503 @ 2.40GHz 	1,757 	intel
2434 	AMD Phenom X4 Quad-Core GP-9500 	1,757 	AMD
2435 	AMD Phenom X2 Dual-Core GE-7060 	1,752 	AMD
2436 	AMD Embedded G-Series GX-215JJ Radeon R2E 	1,750 	AMD
2437 	Intel Celeron J4025 @ 2.00GHz 	1,750 	intel
2438 	MT6797X 	1,749 	via
2439 	MediaTek MT6797X 	1,749 	via
2440 	Intel Xeon 5150 @ 2.66GHz 	1,748 	intel
2441 	Intel Core2 Duo E8135 @ 2.66GHz 	1,746 	intel
2442 	Intel Core i7-660UM @ 1.33GHz 	1,745 	intel
2443 	AMD Athlon II X2 250 	1,743 	AMD
2444 	Intel Core2 Duo P8800 @ 2.66GHz 	1,741 	intel
2445 	Intel Pentium E5700 @ 3.00GHz 	1,738 	intel
2446 	Intel Core2 Duo P9600 @ 2.53GHz 	1,738 	intel
2447 	AMD Phenom II P840 Triple-Core 	1,738 	AMD
2448 	Intel Core2 Duo T9400 @ 2.53GHz 	1,736 	intel
2449 	Intel Celeron 1037U @ 1.80GHz 	1,735 	intel
2450 	Intel Celeron N2940 @ 1.83GHz 	1,735 	intel
2451 	MediaTek MT6757V 	1,729 	via
2452 	Intel Core2 Duo E7300 @ 2.66GHz 	1,726 	intel
2453 	Intel Pentium B940 @ 2.00GHz 	1,725 	intel
2454 	MediaTek MT6797T 	1,723 	via
2455 	AMD Phenom X2 Dual-Core GE-6060 	1,722 	AMD
2456 	Intel Core i3-2340UE @ 1.30GHz 	1,719 	intel
2457 	Intel Celeron B840 @ 1.90GHz 	1,719 	intel
2458 	Intel Celeron G530T @ 2.00GHz 	1,717 	intel
2459 	MediaTek MT8768WT 	1,716 	via
2460 	AMD Phenom II N640 Dual-Core 	1,716 	AMD
2461 	Samsung Exynos 9610 	1,716 	via
2462 	AMD Athlon 7850 Dual-Core 	1,715 	AMD
2463 	Intel Core2 Duo E6750 @ 2.66GHz 	1,714 	intel
2464 	AMD Sempron 3850 APU 	1,714 	AMD
2465 	MT6757W 	1,712 	via
2466 	Intel Pentium B950 @ 2.10GHz 	1,711 	intel
2467 	AMD Athlon II X2 B22 	1,710 	AMD
2468 	Intel Core i7-680UM @ 1.47GHz 	1,710 	intel
2469 	AMD Phenom II X2 B53 	1,709 	AMD
2470 	Intel Pentium E6300 @ 2.80GHz 	1,708 	intel
2471 	MT6763V/CT 	1,708 	via
2472 	AMD Athlon II X2 245e 	1,706 	AMD
2473 	Intel Core i3-2367M @ 1.40GHz 	1,704 	intel
2474 	Intel Pentium 3556U @ 1.70GHz 	1,704 	intel
2475 	Intel Celeron U1900 @ 1.99GHz 	1,704 	intel
2476 	AMD Phenom 8600 Triple-Core 	1,703 	AMD
2477 	Intel Celeron 3755U @ 1.70GHz 	1,702 	intel
2478 	AMD Opteron 2220 	1,701 	AMD
2479 	AMD Athlon II X2 240e 	1,700 	AMD
2480 	AMD Phenom X2 Dual-Core GE-4060 	1,697 	AMD
2481 	AMD Athlon X2 250 	1,696 	AMD
2482 	Intel Atom x5-Z8500 @ 1.44GHz 	1,695 	intel
2483 	Intel Atom x6211E @ 1.20GHz 	1,695 	intel
2484 	Intel Core i3-3229Y @ 1.40GHz 	1,693 	intel
2485 	Intel Core2 Duo E6700 @ 2.66GHz 	1,692 	intel
2486 	HiSilicon Kirin 659 	1,692 	via
2487 	MediaTek MT8768CT 	1,691 	via
2488 	AMD A6-9200 	1,688 	AMD
2489 	Intel Core2 Duo X7360 @ 2.53GHz 	1,687 	intel
2490 	Intel Pentium 3558U @ 1.70GHz 	1,686 	intel
2491 	Intel Core i3-2365M @ 1.40GHz 	1,681 	intel
2492 	AMD Phenom II N620 Dual-Core 	1,681 	AMD
2493 	Intel Core2 Extreme X7900 @ 2.80GHz 	1,681 	intel
2494 	AMD A4-3420 APU 	1,679 	AMD
2495 	MT6763V/WT 	1,678 	via
2496 	AArch64 rev 4 (aarch64) 	1,678 	via
2497 	MT6765 	1,677 	via
2498 	Qualcomm Technologies, Inc SDM630 	1,676 	via
2499 	Intel Celeron 1000M @ 1.80GHz 	1,675 	intel
2500 	Intel Core2 Duo SP9400 @ 2.40GHz 	1,675 	intel
2501 	Intel Celeron N3160 @ 1.60GHz 	1,675 	intel
2502 	MediaTek MT6765V/CB 	1,672 	via
2503 	AMD A6-7000 	1,671 	AMD
2504 	AMD Athlon X2 240e 	1,670 	AMD
2505 	Intel Core2 Duo T9300 @ 2.50GHz 	1,670 	intel
2506 	Samsung Exynos 7880 	1,670 	via
2507 	AMD Turion II Ultra Dual-Core Mobile M640 	1,669 	AMD
2508 	Intel Celeron G1101 @ 2.27GHz 	1,667 	intel
2509 	AMD E2-9000 	1,666 	AMD
2510 	Intel Core i5-560UM @ 1.33GHz 	1,664 	intel
2511 	AMD QC-4000 	1,663 	AMD
2512 	AMD Athlon II X2 235e 	1,660 	AMD
2513 	Intel Pentium 2117U @ 1.80GHz 	1,660 	intel
2514 	Intel Core i7-640UM @ 1.20GHz 	1,658 	intel
2515 	Intel Celeron N3150 @ 1.60GHz 	1,658 	intel
2516 	AMD Athlon II X2 245 	1,657 	AMD
2517 	AMD Opteron 1220 	1,653 	AMD
2518 	Intel Celeron 3855U @ 1.60GHz 	1,651 	intel
2519 	Samsung Exynos 7884 	1,645 	via
2520 	MT6765V/WA 	1,644 	via
2521 	AMD Phenom 8250 Triple-Core 	1,644 	AMD
2522 	AMD E2-3800 APU 	1,644 	AMD
2523 	AMD Athlon II X2 240 	1,641 	AMD
2524 	Intel Pentium E5500 @ 2.80GHz 	1,640 	intel
2525 	Intel Celeron 3215U @ 1.70GHz 	1,639 	intel
2526 	Intel Xeon 5140 @ 2.33GHz 	1,639 	intel
2527 	AMD A6-4400M APU 	1,634 	AMD
2528 	AMD Athlon II X2 220 	1,631 	AMD
2529 	Intel Core2 Duo E7200 @ 2.53GHz 	1,631 	intel
2530 	AMD Phenom 8400 Triple-Core 	1,631 	AMD
2531 	Intel Celeron N2930 @ 1.83GHz 	1,628 	intel
2532 	AMD Athlon X2 255 	1,627 	AMD
2533 	Intel Core2 Duo P8700 @ 2.53GHz 	1,624 	intel
2534 	Intel Atom x5-E8000 @ 1.04GHz 	1,623 	intel
2535 	Samsung Exynos 7904 	1,622 	via
2536 	MediaTek MT6765V/CA 	1,619 	via
2537 	Intel Celeron 3965Y @ 1.50GHz 	1,619 	intel
2538 	AMD Phenom 8250e Triple-Core 	1,619 	AMD
2539 	AMD Athlon II X2 4400e 	1,618 	AMD
2540 	AMD A6 PRO-7050B APU 	1,616 	AMD
2541 	Intel Celeron J1850 @ 1.99GHz 	1,614 	intel
2542 	Athlon 64 Dual Core 5400+ 	1,614 	via
2543 	Intel Pentium G2120T @ 2.70GHz 	1,613 	intel
2544 	Samsung Exynos 7420 	1,612 	via
2545 	AMD A4-4300M APU 	1,611 	AMD
2546 	Qualcomm MSM8996PRO-AB 	1,611 	via
2547 	Intel Celeron 2002E @ 1.50GHz 	1,605 	intel
2548 	AMD Athlon 64 X2 Dual Core 6000+ 	1,605 	AMD
2549 	Intel Pentium A1018 @ 2.10GHz 	1,605 	intel
2550 	Intel Core2 Duo T7800 @ 2.60GHz 	1,604 	intel
2551 	AMD Phenom II P820 Triple-Core 	1,604 	AMD
2552 	ZHAOXIN KaiXian KX-6640MA@2.2+GHz 	1,601 	via
2553 	AMD A6-9220e 	1,600 	AMD
2554 	Qualcomm Technologies, Inc MSM8953 	1,598 	via
2555 	Intel Xeon 5133 @ 2.20GHz 	1,598 	intel
2556 	Intel Pentium E5400 @ 2.70GHz 	1,597 	intel
2557 	AMD Phenom II P650 Dual-Core 	1,597 	AMD
2558 	AMD A4-3400 APU 	1,595 	AMD
2559 	AMD Opteron 2218 	1,594 	AMD
2560 	Intel Celeron 2980U @ 1.60GHz 	1,593 	intel
2561 	MT6765V/WB 	1,592 	via
2562 	Intel Xeon 5148 @ 2.33GHz 	1,590 	intel
2563 	AMD Athlon X2 240 	1,589 	AMD
2564 	AMD Turion II N530 Dual-Core 	1,583 	AMD
2565 	ARM phytium FT1500a 4 Core 2000 MHz 	1,579 	via
2566 	AMD Athlon II X2 215 	1,577 	AMD
2567 	AMD R-260H APU 	1,576 	AMD
2568 	Intel Celeron 2981U @ 1.60GHz 	1,576 	intel
2569 	AMD Athlon 7750 Dual-Core 	1,575 	AMD
2570 	AMD Athlon 64 FX-62 Dual Core 	1,573 	AMD
2571 	Intel Xeon 3085 @ 3.00GHz 	1,570 	intel
2572 	Intel Celeron J4005 @ 2.00GHz 	1,569 	intel
2573 	AMD Phenom X2 Dual-Core GE-5060 	1,566 	AMD
2574 	Intel Core2 Duo P9300 @ 2.26GHz 	1,564 	intel
2575 	AMD Athlon II N370 Dual-Core 	1,559 	AMD
2576 	Intel Core i3-2357M @ 1.30GHz 	1,556 	intel
2577 	HiSilicon Kirin 650 	1,555 	via
2578 	Intel Core2 Duo E6600 @ 2.40GHz 	1,553 	intel
2579 	Apple A8 	1,549 	via
2580 	MT8788 	1,548 	via
2581 	Athlon 64 Dual Core 5600+ 	1,548 	via
2582 	AMD A4 Micro-6400T APU 	1,544 	AMD
2583 	AMD Athlon X2 215 	1,543 	AMD
2584 	AMD A4-9120C 	1,539 	AMD
2585 	Intel Pentium E5300 @ 2.60GHz 	1,538 	intel
2586 	Intel Core2 Duo P8600 @ 2.40GHz 	1,536 	intel
2587 	AMD Turion II Ultra Dual-Core Mobile M660 	1,533 	AMD
2588 	AMD Athlon 64 X2 Dual Core 5800+ 	1,528 	AMD
2589 	AMD Athlon II X2 225 	1,526 	AMD
2590 	AMD A6-1450 APU 	1,523 	AMD
2591 	AMD Turion II N550 Dual-Core 	1,521 	AMD
2592 	Intel Core2 Duo E8135 @ 2.40GHz 	1,520 	intel
2593 	Intel Celeron 3205U @ 1.50GHz 	1,520 	intel
2594 	Intel Celeron B830 @ 1.80GHz 	1,520 	intel
2595 	Intel Xeon 3065 @ 2.33GHz 	1,520 	intel
2596 	Intel Celeron 1017U @ 1.60GHz 	1,519 	intel
2597 	Intel Pentium N3510 @ 1.99GHz 	1,519 	intel
2598 	AMD Opteron 2216 	1,518 	AMD
2599 	Intel Xeon 3060 @ 2.40GHz 	1,518 	intel
2600 	Intel Core2 Duo P7550 @ 2.26GHz 	1,516 	intel
2601 	AMD E2-9030 	1,515 	AMD
2602 	AMD Turion II P560 Dual-Core 	1,513 	AMD
2603 	AMD Sempron X2 190 	1,509 	AMD
2604 	Athlon 64 Dual Core 5000+ 	1,507 	via
2605 	AMD Athlon II X2 4450e 	1,504 	AMD
2606 	AMD A4-3300 APU 	1,504 	AMD
2607 	AMD PRO A4-4350B 	1,502 	AMD
2608 	ARM Cortex-A72 4 Core 1800 MHz 	1,501 	via
2609 	Intel Core2 Duo E6550 @ 2.33GHz 	1,499 	intel
2610 	Intel Celeron N2920 @ 1.86GHz 	1,499 	intel
2611 	Intel Atom E3845 @ 1.91GHz 	1,499 	intel
2612 	AMD GX-412HC 	1,497 	AMD
2613 	AMD Athlon 64 FX-74 	1,495 	AMD
2614 	Qualcomm Technologies, Inc MSM8976SG 	1,489 	via
2615 	Intel Pentium E5200 @ 2.50GHz 	1,488 	intel
2616 	AMD Athlon II X2 210e 	1,486 	AMD
2617 	AMD Athlon 64 X2 Dual Core 5600+ 	1,484 	AMD
2618 	MediaTek MT6762V/WB 	1,483 	via
2619 	Intel Core2 Duo E4700 @ 2.60GHz 	1,483 	intel
2620 	AMD A6-5345M APU 	1,476 	AMD
2621 	Intel Core2 Duo T8300 @ 2.40GHz 	1,474 	intel
2622 	AMD 3015Ce 	1,474 	AMD
2623 	MT6757WD 	1,474 	via
2624 	AMD Opteron 285 	1,470 	AMD
2625 	MediaTek MT8768WA 	1,470 	via
2626 	Samsung Exynos 7885 	1,470 	via
2627 	Intel Celeron N4000 @ 1.10GHz 	1,469 	intel
2628 	AMD Opteron 1218 	1,468 	AMD
2629 	AMD Opteron 290 	1,464 	AMD
2630 	MT6763V/B 	1,461 	via
2631 	Intel Core2 Duo E6540 @ 2.33GHz 	1,458 	intel
2632 	AMD Athlon 7550 Dual-Core 	1,458 	AMD
2633 	Intel Core2 Duo P8400 @ 2.26GHz 	1,455 	intel
2634 	Intel Celeron E3500 @ 2.70GHz 	1,454 	intel
2635 	AMD TurionX2 Ultra DualCore Mobile ZM-85 	1,454 	AMD
2636 	Intel Celeron 5205U @ 1.90GHz 	1,451 	intel
2637 	Intel Core2 Duo P7570 @ 2.26GHz 	1,450 	intel
2638 	AMD Athlon 7450 Dual-Core 	1,448 	AMD
2639 	AMD Athlon 64 X2 Dual Core 5400+ 	1,446 	AMD
2640 	AMD Opteron 1218 HE 	1,444 	AMD
2641 	Qualcomm Technologies, Inc APQ8076 	1,444 	via
2642 	Intel Celeron 2957U @ 1.40GHz 	1,441 	intel
2643 	Intel Celeron E3400 @ 2.60GHz 	1,439 	intel
2644 	Nvidia Tegra T210 	1,436 	via
2645 	AMD Phenom X2 Dual-Core GP-7730 	1,435 	AMD
2646 	AMD Turion II P540 Dual-Core 	1,429 	AMD
2647 	Intel Celeron B820 @ 1.70GHz 	1,428 	intel
2648 	AMD Turion II Ultra Dual-Core Mobile M620 	1,427 	AMD
2649 	AMD Athlon X2 440 	1,424 	AMD
2650 	Intel Celeron 2955U @ 1.40GHz 	1,419 	intel
2651 	Intel Core2 Duo T7700 @ 2.40GHz 	1,419 	intel
2652 	Intel Core2 Duo P7450 @ 2.13GHz 	1,416 	intel
2653 	AMD Opteron 2214 HE 	1,415 	AMD
2654 	Intel Celeron 4305U @ 2.20GHz 	1,413 	intel
2655 	AMD Sempron X2 198 Dual-Core 	1,413 	AMD
2656 	Intel Celeron B810 @ 1.60GHz 	1,411 	intel
2657 	AMD Turion II Ultra Dual-Core Mobile M600 	1,409 	AMD
2658 	AMD Athlon Dual Core 5400B 	1,405 	AMD
2659 	MT6755V/B 	1,404 	via
2660 	AMD E2-3200 APU 	1,401 	AMD
2661 	Intel Xeon E5205 @ 1.86GHz 	1,401 	intel
2662 	AMD Opteron 2220 SE 	1,398 	AMD
2663 	MediaTek MT6762V/WD 	1,397 	via
2664 	Intel Xeon E5503 @ 2.00GHz 	1,396 	intel
2665 	Intel Pentium 997 @ 1.60GHz 	1,395 	intel
2666 	Intel Celeron E3200 @ 2.40GHz 	1,394 	intel
2667 	Intel Celeron 1007U @ 1.50GHz 	1,392 	intel
2668 	AMD Athlon Dual Core 4850B 	1,391 	AMD
2669 	Hisilicon Kirin 930 	1,390 	via
2670 	Qualcomm Technologies, Inc APQ8096 	1,389 	via
2671 	Intel Core2 Duo E4600 @ 2.40GHz 	1,385 	intel
2672 	AMD E1-6050J APU 	1,385 	AMD
2673 	Intel Pentium 4425Y @ 1.70GHz 	1,383 	intel
2674 	AMD Athlon 64 X2 Dual Core 5200+ 	1,383 	AMD
2675 	Intel Celeron E3300 @ 2.50GHz 	1,382 	intel
2676 	Intel Core2 Duo T7600 @ 2.33GHz 	1,380 	intel
2677 	Intel Pentium P6300 @ 2.27GHz 	1,380 	intel
2678 	Intel Xeon 5130 @ 2.00GHz 	1,378 	intel
2679 	Intel Xeon E5502 @ 1.87GHz 	1,378 	intel
2680 	AMD Turion II Neo N54L Dual-Core 	1,376 	AMD
2681 	Intel Core i5-540UM @ 1.20GHz 	1,374 	intel
2682 	Athlon 64 Dual Core 4800+ 	1,370 	via
2683 	Intel Core2 Duo T6670 @ 2.20GHz 	1,368 	intel
2684 	Qualcomm Technologies, Inc MSM8976 	1,367 	via
2685 	Intel Celeron B815 @ 1.60GHz 	1,366 	intel
2686 	VIA QuadCore L4700 @ 1.2+ GHz 	1,363 	via
2687 	Intel Core2 Duo T6600 @ 2.20GHz 	1,362 	intel
2688 	AMD E2-9000e 	1,361 	AMD
2689 	AMD Opteron 185 	1,360 	AMD
2690 	MediaTek MT6762V/WR 	1,360 	via
2691 	Intel Core2 Duo E6420 @ 2.13GHz 	1,360 	intel
2692 	MT6755V/WS 	1,359 	via
2693 	AMD Opteron 2214 	1,358 	AMD
2694 	AMD Turion II P520 Dual-Core 	1,357 	AMD
2695 	Intel Core i5-520UM @ 1.07GHz 	1,356 	intel
2696 	AMD Athlon II X2 270u 	1,350 	AMD
2697 	AMD Athlon II X2 4300e 	1,350 	AMD
2698 	Intel Pentium P6200 @ 2.13GHz 	1,349 	intel
2699 	AMD Athlon Dual Core 5050e 	1,347 	AMD
2700 	ARM Cortex-A57 4 Core 2014 MHz 	1,343 	via
2701 	Intel Celeron P4600 @ 2.00GHz 	1,340 	intel
2702 	Intel Core i5-430UM @ 1.20GHz 	1,339 	intel
2703 	Intel Xeon L3406 @ 2.27GHz 	1,338 	intel
2704 	AMD Turion II Dual-Core Mobile M540 	1,338 	AMD
2705 	Intel Pentium T4500 @ 2.30GHz 	1,336 	intel
2706 	Intel Pentium E2220 @ 2.40GHz 	1,331 	intel
2707 	Intel Core2 Extreme X7850 @ 2.80GHz 	1,331 	intel
2708 	Intel Pentium P6100 @ 2.00GHz 	1,327 	intel
2709 	Athlon Dual Core 4850e 	1,327 	via
2710 	Intel Core i7-620UM @ 1.07GHz 	1,323 	intel
2711 	AMD Athlon Dual Core 5200B 	1,319 	AMD
2712 	Intel Core2 Duo L9600 @ 2.13GHz 	1,318 	intel
2713 	AMD Athlon II P360 Dual-Core 	1,317 	AMD
2714 	Intel Xeon 3050 @ 2.13GHz 	1,313 	intel
2715 	AMD Athlon 64 X2 Dual Core 5000+ 	1,313 	AMD
2716 	AMD Opteron 1216 	1,311 	AMD
2717 	AMD Athlon Dual Core 4850e 	1,311 	AMD
2718 	AMD Opteron 1212 HE 	1,308 	AMD
2719 	AMD Turion II Dual-Core Mobile M520 	1,305 	AMD
2720 	AMD Athlon Dual Core 5600B 	1,304 	AMD
2721 	Unisoc SC9863a 	1,302 	via
2722 	AMD Athlon Dual Core 5000B 	1,300 	AMD
2723 	AMD Opteron 1214 HE 	1,299 	AMD
2724 	Intel Core2 Duo P7370 @ 2.00GHz 	1,298 	intel
2725 	Intel Celeron G470 @ 2.00GHz 	1,298 	intel
2726 	Intel Core2 Duo T8100 @ 2.10GHz 	1,297 	intel
2727 	AMD Turion X2 Ultra Dual-Core Mobile ZM-86 	1,297 	AMD
2728 	Qualcomm MSM8996 	1,294 	via
2729 	AMD Turion II Dual-Core Mobile M500 	1,294 	AMD
2730 	AMD A4-3310MX APU 	1,292 	AMD
2731 	AMD Athlon 5000 Dual-Core 	1,292 	AMD
2732 	AMD Opteron 275 	1,291 	AMD
2733 	Intel Core2 Duo P7350 @ 2.00GHz 	1,291 	intel
2734 	Intel Core2 Duo E6400 @ 2.13GHz 	1,290 	intel
2735 	Intel Celeron 877 @ 1.40GHz 	1,288 	intel
2736 	Intel Core2 Duo T6500 @ 2.10GHz 	1,287 	intel
2737 	AMD Athlon 64 X2 4200+ 	1,285 	AMD
2738 	Intel Xeon 3040 @ 1.86GHz 	1,284 	intel
2739 	AMD A6-4455M APU 	1,283 	AMD
2740 	Intel Pentium T4400 @ 2.20GHz 	1,282 	intel
2741 	AMD Athlon 64 FX-60 Dual Core 	1,282 	AMD
2742 	Unisoc UIS8581E 	1,279 	via
2743 	Intel Atom Z3775D @ 1.49GHz 	1,278 	intel
2744 	Intel Celeron B800 @ 1.50GHz 	1,278 	intel
2745 	Celeron Dual-Core T3500 @ 2.10GHz 	1,276 	via
2746 	Intel Celeron 887 @ 1.50GHz 	1,274 	intel
2747 	Intel Core2 Duo T7500 @ 2.20GHz 	1,273 	intel
2748 	AMD Opteron 280 	1,272 	AMD
2749 	Intel Core2 Duo E4500 @ 2.20GHz 	1,271 	intel
2750 	AMD Opteron 2212 	1,270 	AMD
2751 	Intel Core2 Duo SL9400 @ 1.86GHz 	1,268 	intel
2752 	AMD Turion X2 Ultra Dual-Core Mobile ZM-87 	1,267 	AMD
2753 	Intel Pentium 3560Y @ 1.20GHz 	1,266 	intel
2754 	Intel Atom x5-Z8350 @ 1.44GHz 	1,266 	intel
2755 	Intel Celeron E1600 @ 2.40GHz 	1,260 	intel
2756 	Intel Atom Z3775 @ 1.46GHz 	1,257 	intel
2757 	Intel Core2 Duo T6570 @ 2.10GHz 	1,255 	intel
2758 	AMD GX-222GC SOC 	1,255 	AMD
2759 	AMD Athlon 64 X2 Dual Core 4800+ 	1,254 	AMD
2760 	Qualcomm Technologies, Inc MSM8992 	1,254 	via
2761 	AMD A4-3320M APU 	1,253 	AMD
2762 	MediaTek MT8183 	1,252 	via
2763 	AMD Athlon X2 Dual Core BE-2450 	1,251 	AMD
2764 	AMD Athlon II P340 Dual-Core 	1,249 	AMD
2765 	Qualcomm Technologies, Inc MSM8996 	1,248 	via
2766 	Intel Pentium P6000 @ 1.87GHz 	1,248 	intel
2767 	AMD Athlon 5200 Dual-Core 	1,248 	AMD
2768 	Intel Xeon 5120 @ 1.86GHz 	1,248 	intel
2769 	AMD Athlon II N350 Dual-Core 	1,247 	AMD
2770 	Intel Core2 Duo T7400 @ 2.16GHz 	1,246 	intel
2771 	Intel Atom Z3770 @ 1.46GHz 	1,245 	intel
2772 	Intel Atom C3338 @ 1.50GHz 	1,245 	intel
2773 	MediaTek MT6762V/CB 	1,243 	via
2774 	AMD Opteron 180 	1,234 	AMD
2775 	AMD Turion X2 Ultra Dual-Core Mobile ZM-85 	1,234 	AMD
2776 	Athlon 64 Dual Core 3800+ 	1,234 	via
2777 	Intel Pentium T4300 @ 2.10GHz 	1,233 	intel
2778 	MediaTek MT6763V/V 	1,231 	via
2779 	Qualcomm Technologies, Inc MSM8956 	1,231 	via
2780 	Qualcomm Technologies, Inc MSM8996pro 	1,226 	via
2781 	Intel Celeron N4000C @ 1.10GHz 	1,226 	intel
2782 	Intel Pentium 987 @ 1.50GHz 	1,226 	intel
2783 	Intel Core2 Duo T6400 @ 2.00GHz 	1,225 	intel
2784 	AMD Sempron X2 180 	1,222 	AMD
2785 	AMD Athlon 64 X2 Dual Core 4600+ 	1,222 	AMD
2786 	Intel Xeon E5-26xx v4 	1,222 	intel
2787 	AMD A4-3305M APU 	1,221 	AMD
2788 	AMD Athlon II P320 Dual-Core 	1,216 	AMD
2789 	AMD A4-3330MX APU 	1,213 	AMD
2790 	AMD Athlon X2 Dual Core BE-2400 	1,213 	AMD
2791 	AMD Turion X2 Ultra Dual-Core Mobile ZM-84 	1,213 	AMD
2792 	AMD Phenom X4 Quad-Core GS-5560 	1,211 	AMD
2793 	Intel Core2 Duo T5900 @ 2.20GHz 	1,207 	intel
2794 	Dual-Core AMD Opteron 1220 SE 	1,206 	AMD
2795 	Intel Pentium E2200 @ 2.20GHz 	1,204 	intel
2796 	Intel Celeron N2910 @ 1.60GHz 	1,203 	intel
2797 	Celeron Dual-Core T3300 @ 2.00GHz 	1,200 	via
2798 	Intel Core2 Duo T5850 @ 2.16GHz 	1,195 	intel
2799 	Intel Atom x5-Z8300 @ 1.44GHz 	1,195 	intel
2800 	Intel Core2 Duo T7300 @ 2.00GHz 	1,192 	intel
2801 	AMD Opteron 1214 	1,191 	AMD
2802 	Intel Celeron 1047UE @ 1.40GHz 	1,188 	intel
2803 	AMD Turion II Neo K685 Dual-Core 	1,186 	AMD
2804 	Intel Core2 Duo E6320 @ 1.86GHz 	1,185 	intel
2805 	AMD A4-3300M APU 	1,185 	AMD
2806 	Intel Celeron J3355 @ 2.00GHz 	1,183 	intel
2807 	AMD Phenom X2 Dual-Core GP-5000 	1,180 	AMD
2808 	AMD A4-4355M APU 	1,175 	AMD
2809 	Intel Pentium E2210 @ 2.20GHz 	1,174 	intel
2810 	Intel Celeron 867 @ 1.30GHz 	1,173 	intel
2811 	VIA QuadCore U4650 @ 1.0+ GHz 	1,173 	via
2812 	AMD Opteron 1216 HE 	1,172 	AMD
2813 	Intel Xeon Gold 6133 @ 2.50GHz 	1,172 	intel
2814 	Intel Celeron E1500 @ 2.20GHz 	1,172 	intel
2815 	MT6755V/CM 	1,172 	via
2816 	MT6755M 	1,172 	via
2817 	Intel Core i3-380UM @ 1.33GHz 	1,168 	intel
2818 	Celeron Dual-Core T3100 @ 1.90GHz 	1,168 	via
2819 	AMD Opteron 175 	1,167 	AMD
2820 	MediaTek MT6762V/WA 	1,167 	via
2821 	Intel Core2 Duo T7200 @ 2.00GHz 	1,166 	intel
2822 	AMD Turion 64 X2 Mobile TL-68 	1,162 	AMD
2823 	Intel Atom E3840 @ 1.91GHz 	1,162 	intel
2824 	AMD Athlon Dual Core 4450B 	1,162 	AMD
2825 	MT6757WH 	1,161 	via
2826 	Intel Pentium 967 @ 1.30GHz 	1,160 	intel
2827 	MTK6757 	1,158 	via
2828 	Intel Core2 Duo E4400 @ 2.00GHz 	1,157 	intel
2829 	Athlon 64 Dual Core 4200+ 	1,156 	via
2830 	AMD Athlon II N330 Dual-Core 	1,154 	AMD
2831 	AMD Turion X2 Dual-Core Mobile RM-77 	1,149 	AMD
2832 	Intel Pentium 977 @ 1.40GHz 	1,148 	intel
2833 	VIA Eden X4 C4250 @ 1.2+GHz 	1,147 	via
2834 	Intel Celeron 857 @ 1.20GHz 	1,146 	intel
2835 	Intel Pentium T4200 @ 2.00GHz 	1,146 	intel
2836 	AMD Athlon 64 X2 Dual Core 4400+ 	1,146 	AMD
2837 	Qualcomm Technologies, Inc SDM439 	1,145 	via
2838 	Intel Core2 Duo T5870 @ 2.00GHz 	1,144 	intel
2839 	AMD Athlon II Dual-Core M320 	1,142 	AMD
2840 	AMD Turion 64 X2 Mobile TL-66 	1,141 	AMD
2841 	AMD Turion X2 Dual-Core Mobile RM-75 	1,137 	AMD
2842 	Intel Core2 Duo U9600 @ 1.60GHz 	1,133 	intel
2843 	Intel Celeron P4500 @ 1.87GHz 	1,119 	intel
2844 	Intel Core2 Duo L7800 @ 2.00GHz 	1,116 	intel
2845 	Intel Celeron N3350 @ 1.10GHz 	1,116 	intel
2846 	AMD GX-218GL SOC 	1,115 	AMD
2847 	AMD Athlon II Dual-Core M300 	1,114 	AMD
2848 	Intel Pentium T3400 @ 2.16GHz 	1,113 	intel
2849 	Intel Core2 Duo T7250 @ 2.00GHz 	1,111 	intel
2850 	Intel Celeron 2961Y @ 1.10GHz 	1,110 	intel
2851 	AMD Turion 64 X2 Mobile TL-64 	1,110 	AMD
2852 	Intel Core2 Duo E6300 @ 1.86GHz 	1,109 	intel
2853 	MediaTek MT6750V/WT 	1,108 	via
2854 	Intel Core2 Duo T5800 @ 2.00GHz 	1,108 	intel
2855 	AMD Athlon64 X2 Dual Core 4600+ 	1,108 	AMD
2856 	AMD Athlon II X2 260u 	1,107 	AMD
2857 	Samsung J7 Max LTE SWA board based on MT6757V/WL 	1,104 	via
2858 	AMD Athlon X2 Dual Core BE-2350 	1,104 	AMD
2859 	AMD Athlon Dual Core 4450e 	1,102 	AMD
2860 	AMD Opteron 170 	1,097 	AMD
2861 	AMD Athlon 64 X2 Dual Core 4200+ 	1,097 	AMD
2862 	AMD GX-217GA SOC 	1,097 	AMD
2863 	AMD Athlon 64 X2 Dual Core BE-230 	1,095 	AMD
2864 	Intel Pentium 957 @ 1.20GHz 	1,095 	intel
2865 	AMD E2-3000M APU 	1,092 	AMD
2866 	Intel Core2 Duo T5750 @ 2.00GHz 	1,091 	intel
2867 	ARM Cortex-A72 4 Core 2000 MHz 	1,088 	via
2868 	AMD E2-3000 APU 	1,088 	AMD
2869 	Intel Pentium E2180 @ 2.00GHz 	1,087 	intel
2870 	MediaTek MT6750T 	1,087 	via
2871 	AMD Turion 64 X2 Mobile TL-62 	1,087 	AMD
2872 	AMD Athlon Dual Core 4050e 	1,086 	AMD
2873 	AMD Turion X2 Dual-Core Mobile RM-72 	1,085 	AMD
2874 	Qualcomm MSM 8939 HUAWEI TEXAS-A1 	1,085 	via
2875 	AMD Turion X2 Ultra Dual-Core Mobile ZM-82 	1,084 	AMD
2876 	Celeron Dual-Core T3000 @ 1.80GHz 	1,084 	via
2877 	AMD Opteron 270 	1,083 	AMD
2878 	AMD Athlon 64 X2 Dual Core BE-2300 	1,082 	AMD
2879 	AMD Sempron Dual Core 4900 	1,081 	AMD
2880 	Athlon Dual Core 4450e 	1,081 	via
2881 	Intel Core i5-470UM @ 1.33GHz 	1,081 	intel
2882 	Intel Atom Z3745 @ 1.33GHz 	1,079 	intel
2883 	Intel Xeon 5110 @ 1.60GHz 	1,079 	intel
2884 	Qualcomm MSM8937 	1,072 	via
2885 	Intel Core i3-330UM @ 1.20GHz 	1,071 	intel
2886 	Qualcomm MSM 8939 HUAWEI KIW-L21 	1,068 	via
2887 	Intel Core2 Duo L9300 @ 1.60GHz 	1,067 	intel
2888 	MediaTek MT6750 	1,064 	via
2889 	Intel Celeron G465 @ 1.90GHz 	1,064 	intel
2890 	AMD Phenom X4 Quad-Core GS-6560 	1,063 	AMD
2891 	Intel Atom Z3740 @ 1.33GHz 	1,062 	intel
2892 	AMD Turion X2 Dual-Core Mobile RM-74 	1,062 	AMD
2893 	AMD Turion X2 Dual Core Mobile RM-76 	1,059 	AMD
2894 	Intel Celeron T1700 @ 1.83GHz 	1,058 	intel
2895 	Intel Pentium 2129Y @ 1.10GHz 	1,057 	intel
2896 	AMD Athlon II Dual-Core M340 	1,056 	AMD
2897 	Qualcomm MSM 8939 HUAWEI KIW-L24 	1,051 	via
2898 	Intel Core2 Duo E4300 @ 1.80GHz 	1,050 	intel
2899 	Intel Celeron E1400 @ 2.00GHz 	1,048 	intel
2900 	AMD Athlon 64 X2 QL-65 	1,046 	AMD
2901 	Intel Core2 Duo T5550 @ 1.83GHz 	1,045 	intel
2902 	AMD Athlon 64 X2 Dual Core BE-2350 	1,044 	AMD
2903 	Intel Xeon 3.73GHz 	1,041 	intel
2904 	AMD Athlon 64 X2 Dual Core 4000+ 	1,041 	AMD
2905 	Intel Celeron J1750 @ 2.41GHz 	1,037 	intel
2906 	Intel Atom Z3745D @ 1.33GHz 	1,034 	intel
2907 	MediaTek MT6757CD 	1,033 	via
2908 	Intel Pentium T3200 @ 2.00GHz 	1,029 	intel
2909 	Intel Core2 Duo T5600 @ 1.83GHz 	1,028 	intel
2910 	Intel Celeron G460 @ 1.80GHz 	1,028 	intel
2911 	Intel Celeron 847E @ 1.10GHz 	1,026 	intel
2912 	AMD TurionX2 Dual Core Mobile RM-72 	1,026 	AMD
2913 	Intel Celeron J1800 @ 2.41GHz 	1,025 	intel
2914 	Intel 1500 @ 2.00GHz 	1,024 	intel
2915 	Intel Core Duo T2700 @ 2.33GHz 	1,024 	intel
2916 	Intel Atom Z3740D @ 1.33GHz 	1,023 	intel
2917 	Intel Core2 Duo P7700 @ 1.80GHz 	1,021 	intel
2918 	Intel Core2 Duo T7100 @ 1.80GHz 	1,018 	intel
2919 	Intel Atom x5-Z8330 @ 1.44GHz 	1,017 	intel
2920 	AMD Turion Dual-Core RM-74 	1,016 	AMD
2921 	AMD Turion X2 Ultra Dual-Core Mobile ZM-80 	1,014 	AMD
2922 	AMD Athlon 64 X2 QL-62 	1,014 	AMD
2923 	Qualcomm MSM8939 	1,013 	via
2924 	Qualcomm Technologies, Inc MSM8937 	1,010 	via
2925 	AMD Opteron 1212 	1,009 	AMD
2926 	AMD Athlon X2 Dual Core LS-5800 	1,009 	AMD
2927 	Qualcomm Technologies, Inc SDA450 	1,006 	via
2928 	AMD Athlon 64 X2 QL-67 	1,006 	AMD
2929 	Intel Celeron N2840 @ 2.16GHz 	1,004 	intel
2930 	Pentium Dual-Core T4500 @ 2.30GHz 	1,003 	via
2931 	AMD Athlon Neo X2 Dual Core 6850e 	1,002 	AMD
2932 	AMD Athlon 64 X2 Dual Core 3800+ 	1,001 	AMD
2933 	Qualcomm MSM8992 	1,001 	via
2934 	AMD Athlon II X2 250u 	1,000 	AMD
2935 	AMD Athlon X2 Dual Core 6850e 	998 	AMD
2936 	MediaTek MT6765G 	997 	via
2937 	AMD Turion X2 Dual-Core Mobile RM-70 	997 	AMD
2938 	AMD TurionX2 Dual Core Mobile RM-70 	997 	AMD
2939 	Intel Pentium E2160 @ 1.80GHz 	996 	intel
2940 	Qualcomm Technologies, Inc MSM8994 	996 	via
2941 	Intel Pentium T2410 @ 2.00GHz 	996 	intel
2942 	AMD Sempron Dual Core 2200 	995 	AMD
2943 	AMD Turion 64 X2 Mobile TL-60 	994 	AMD
2944 	AMD Athlon 64 X2 Dual Core 3400+ 	994 	AMD
2945 	Intel Celeron P4505 @ 1.87GHz 	994 	intel
2946 	Intel Core2 Duo T5670 @ 1.80GHz 	993 	intel
2947 	AMD E1-7010 APU 	993 	AMD
2948 	AMD Athlon 64 X2 QL-64 	989 	AMD
2949 	AMD Athlon 64 X2 TK-57 	988 	AMD
2950 	Intel Celeron N3060 @ 1.60GHz 	985 	intel
2951 	Qualcomm Technologies, Inc MSM8940 	984 	via
2952 	AMD Sempron Dual Core 2300 	982 	AMD
2953 	Nvidia Tegra T132 	981 	via
2954 	Intel Celeron J3060 @ 1.60GHz 	981 	intel
2955 	Intel 1400 @ 1.83GHz 	980 	intel
2956 	AMD Turion Dual-Core RM-75 	977 	AMD
2957 	MT6755V/WM 	976 	via
2958 	MediaTek MT6753T 	975 	via
2959 	Intel Core2 Duo L7700 @ 1.80GHz 	973 	intel
2960 	AMD Turion II Neo K625 Dual-Core 	973 	AMD
2961 	tn8 	972 	via
2962 	AMD Opteron 1210 HE 	971 	AMD
2963 	AMD Athlon 64 X2 Dual Core TK-57 	971 	AMD
2964 	Intel Pentium Extreme Edition 965 @ 3.73GHz 	969 	intel
2965 	MT6795M 	968 	via
2966 	Athlon Dual Core 4050e 	968 	via
2967 	AMD Athlon 64 X2 Dual Core 3600+ 	967 	AMD
2968 	Intel Celeron @ 1.30GHz 	965 	intel
2969 	Intel Celeron N3010 @ 1.04GHz 	964 	intel
2970 	AMD Opteron 256 	963 	AMD
2971 	AMD Opteron 265 	963 	AMD
2972 	Intel Core2 Duo L7500 @ 1.60GHz 	963 	intel
2973 	ARM Cortex-A57 4 Core 1479 MHz 	962 	via
2974 	Intel Atom C2358 @ 1.74GHz 	961 	intel
2975 	AMD E1 Micro-6200T APU 	960 	AMD
2976 	Intel T2050 @ 2.00GHz 	959 	intel
2977 	MediaTek MT6762G 	958 	via
2978 	AMD Athlon 64 X2 3800+ 	958 	AMD
2979 	AMD Athlon 64 X2 TK-55 	955 	AMD
2980 	Qualcomm Technologies, Inc SDM450 	953 	via
2981 	Intel T1500 @ 1.86GHz 	953 	intel
2982 	Intel Celeron N2830 @ 2.16GHz 	951 	intel
2983 	Intel Celeron T1600 @ 1.66GHz 	950 	intel
2984 	MT8768WD 	949 	via
2985 	AMD Sempron Dual Core 4700 	948 	AMD
2986 	AMD Athlon 64 X2 QL-66 	947 	AMD
2987 	Intel Core2 Duo P7500 @ 1.60GHz 	945 	intel
2988 	Intel Pentium T2390 @ 1.86GHz 	945 	intel
2989 	AMD Turion 64 X2 Mobile TL-58 	944 	AMD
2990 	Intel Pentium U5600 @ 1.33GHz 	943 	intel
2991 	Intel Core Duo T2600 @ 2.16GHz 	941 	intel
2992 	AMD Sempron 2650 APU 	939 	AMD
2993 	AMD Sempron Dual Core 2100 	936 	AMD
2994 	Intel Celeron 847 @ 1.10GHz 	936 	intel
2995 	Intel Core2 Duo T5300 @ 1.73GHz 	935 	intel
2996 	Intel Core2 Duo SU9400 @ 1.40GHz 	933 	intel
2997 	Intel T1400 @ 1.73GHz 	929 	intel
2998 	Intel Celeron N2820 @ 2.13GHz 	928 	intel
2999 	Intel Atom Z3735E @ 1.33GHz 	927 	intel
3000 	Intel Celeron 1019Y @ 1.00GHz 	926 	intel
3001 	AMD Athlon X2 Dual Core BE-2300 	925 	AMD
3002 	Intel Core2 Duo T5500 @ 1.66GHz 	925 	intel
3003 	AMD Turion II Neo N40L Dual-Core 	924 	AMD
3004 	AMD Athlon 64 X2 Dual-Core TK-57 	924 	AMD
3005 	AMD Opteron 1210 	923 	AMD
3006 	AMD Turion X2 Dual Core L510 	923 	AMD
3007 	Intel Atom Z3736F @ 1.33GHz 	922 	intel
3008 	Intel Celeron N2808 @ 1.58GHz 	922 	intel
3009 	Qualcomm Technologies, Inc SDM429 	918 	via
3010 	AMD Athlon 64 X2 QL-60 	918 	AMD
3011 	Intel Atom S1260 @ 2.00GHz 	916 	intel
3012 	Intel Atom Z3735D @ 1.33GHz 	914 	intel
3013 	Intel Pentium Extreme Edition 955 @ 3.46GHz 	912 	intel
3014 	Intel Core2 Duo T5450 @ 1.66GHz 	912 	intel
3015 	Intel Atom Z3735G @ 1.33GHz 	909 	intel
3016 	Intel Core2 Duo T5470 @ 1.60GHz 	909 	intel
3017 	Intel Atom Z3735F @ 1.33GHz 	908 	intel
3018 	AMD Turion Dual-Core RM-70 	904 	AMD
3019 	Intel Celeron N3000 @ 1.04GHz 	901 	intel
3020 	AMD Opteron 165 	899 	AMD
3021 	Intel Atom C2338 @ 1.74GHz 	898 	intel
3022 	Qualcomm MSM8994 	896 	via
3023 	AMD E1-6015 APU 	895 	AMD
3024 	AMD E1-2500 APU 	888 	AMD
3025 	AMD Turion 64 X2 Mobile TL-56 	887 	AMD
3026 	MT8168B 	886 	via
3027 	Intel Celeron N3050 @ 1.60GHz 	880 	intel
3028 	AMD Athlon 64 X2 Dual-Core TK-42 	877 	AMD
3029 	AMD Athlon 64 X2 Dual-Core TK-55 	874 	AMD
3030 	Samsung Exynos 7870 	872 	via
3031 	Intel Core2 Duo U7300 @ 1.30GHz 	871 	intel
3032 	Intel Pentium E2140 @ 1.60GHz 	869 	intel
3033 	Samsung Exynos 7580 	869 	via
3034 	Intel Core Duo T2500 @ 2.00GHz 	868 	intel
3035 	AMD Turion Dual-Core RM-72 	860 	AMD
3036 	Intel Pentium SU4100 @ 1.30GHz 	859 	intel
3037 	Intel Core2 Duo U9300 @ 1.20GHz 	859 	intel
3038 	AMD E1-6010 APU 	859 	AMD
3039 	Intel Celeron E1200 @ 1.60GHz 	858 	intel
3040 	AMD Turion X2 Dual Core Mobile RM-70 	858 	AMD
3041 	Intel Celeron N2815 @ 1.86GHz 	858 	intel
3042 	MT6762V/CR 	857 	via
3043 	Intel 1300 @ 1.66GHz 	857 	intel
3044 	AMD Athlon II Neo K345 Dual-Core 	856 	AMD
3045 	Samsung EXYNOS5433 	855 	via
3046 	ARM Cortex-A72 4 Core 1500 MHz 	853 	via
3047 	Intel Celeron N2807 @ 1.58GHz 	850 	intel
3048 	Intel Atom E3827 @ 1.74GHz 	849 	intel
3049 	Intel Core2 Duo L7400 @ 1.50GHz 	846 	intel
3050 	DO-Regular 	846 	via
3051 	Intel Pentium T1080 @ 1.73GHz 	842 	intel
3052 	Intel Atom D2700 @ 2.13GHz 	842 	intel
3053 	Intel Pentium T2370 @ 1.73GHz 	841 	intel
3054 	AMD Athlon 64 X2 Dual Core TK-53 	839 	AMD
3055 	AMD Athlon 64 X2 Dual Core TK-55 	839 	AMD
3056 	MediaTek MT6762V/CA 	836 	via
3057 	Qualcomm Technologies, Inc MSM8952 	835 	via
3058 	Intel Core2 Duo T5250 @ 1.50GHz 	834 	intel
3059 	Intel Pentium T2330 @ 1.60GHz 	834 	intel
3060 	AMD E2-2000 APU 	830 	AMD
3061 	Intel Core2 Duo T5200 @ 1.60GHz 	829 	intel
3062 	AMD Athlon Neo X2 Dual Core L335 	828 	AMD
3063 	Intel Core2 Duo L7300 @ 1.40GHz 	827 	intel
3064 	Intel Core Duo T2450 @ 2.00GHz 	825 	intel
3065 	BCM2711 	823 	via
3066 	MT6761V/CBB 	822 	via
3067 	AMD Turion Neo X2 Dual Core L625 	819 	AMD
3068 	AMD E2-1800 APU 	818 	AMD
3069 	Intel Pentium D 960 @ 3.60GHz 	817 	intel
3070 	Intel Core2 Duo T5270 @ 1.40GHz 	816 	intel
3071 	AMD Athlon 64 X2 Dual-Core TK-53 	815 	AMD
3072 	Intel Celeron B720 @ 1.70GHz 	814 	intel
3073 	Intel Pentium U5400 @ 1.20GHz 	812 	intel
3074 	Intel Atom x5-E3930 @ 1.30GHz 	811 	intel
3075 	Intel Celeron U3600 @ 1.20GHz 	809 	intel
3076 	AMD Sempron 145 	807 	AMD
3077 	Intel Atom Z3770D @ 1.49GHz 	805 	intel
3078 	SAMSUNG Exynos7580 	798 	via
3079 	Intel Celeron N2806 @ 1.60GHz 	798 	intel
3080 	AMD Athlon 64 FX-25 	794 	AMD
3081 	Intel Core Duo T2400 @ 1.83GHz 	794 	intel
3082 	AMD Athlon II Neo N36L Dual-Core 	793 	AMD
3083 	AMD A4-9120e 	793 	AMD
3084 	MediaTek MT6761V/WE 	792 	via
3085 	MT8766B 	789 	via
3086 	AMD G-T56N 	788 	AMD
3087 	MT6761V/CD 	784 	via
3088 	SAMSUNG Exynos7420 	782 	via
3089 	AMD Athlon X2 Dual Core 3250e 	779 	AMD
3090 	Intel Celeron N2810 @ 2.00GHz 	777 	intel
3091 	AMD Athlon Neo X2 Dual Core L325 	776 	AMD
3092 	Qualcomm APQ 8084 (Flattened Device Tree) 	776 	via
3093 	AMD Athlon II Neo K325 Dual-Core 	775 	AMD
3094 	Intel Celeron SU2300 @ 1.20GHz 	772 	intel
3095 	MT8165 	769 	via
3096 	AMD E-450 APU 	767 	AMD
3097 	AMD E1-2200 APU 	767 	AMD
3098 	Spreadtrum SC9853I-IA 	766 	via
3099 	AMD Turion 64 X2 Mobile TL-52 	765 	AMD
3100 	MediaTek MT8166B 	762 	via
3101 	AMD Opteron 252 	760 	AMD
3102 	Intel Core2 Duo L7100 @ 1.20GHz 	760 	intel
3103 	Intel Core Duo T2350 @ 1.86GHz 	760 	intel
3104 	AMD Sempron LE-1640 	759 	AMD
3105 	AMD E-350 APU 	759 	AMD
3106 	Intel Core Duo T2250 @ 1.73GHz 	758 	intel
3107 	Intel Celeron 807 @ 1.50GHz 	751 	intel
3108 	AMD G-T56E 	751 	AMD
3109 	AMD E-350 	748 	AMD
3110 	AMD Turion 64 X2 Mobile TL-50 	747 	AMD
3111 	AMD GX-212JC SOC 	744 	AMD
3112 	Intel Pentium D 950 @ 3.40GHz 	743 	intel
3113 	Qualcomm Technologies, Inc MSM8939 	742 	via
3114 	AMD Sempron 140 	734 	AMD
3115 	Intel Celeron U3400 @ 1.07GHz 	733 	intel
3116 	Intel Pentium T2310 @ 1.46GHz 	730 	intel
3117 	AMD Athlon 64 FX-57 	730 	AMD
3118 	Intel Core Duo T2300 @ 1.66GHz 	729 	intel
3119 	Intel Core Duo L2500 @ 1.83GHz 	728 	intel
3120 	AMD G-T48E 	724 	AMD
3121 	AMD E-350D APU 	723 	AMD
3122 	AMD Athlon 64 FX-55 	721 	AMD
3123 	Intel Atom D2701 @ 2.13GHz 	720 	intel
3124 	Intel Core Duo L2300 @ 1.50GHz 	719 	intel
3125 	MT6795 	717 	via
3126 	AMD Athlon 64 FX-59 	715 	AMD
3127 	Qualcomm Technologies, Inc MSM8929 	714 	via
3128 	Intel Atom D2560 @ 2.00GHz 	711 	intel
3129 	Intel Core Duo L2400 @ 1.66GHz 	711 	intel
3130 	Intel Pentium T2130 @ 1.86GHz 	710 	intel
3131 	Intel Pentium D 940 @ 3.20GHz 	709 	intel
3132 	ARM Cortex-A72 4 Core 2200 MHz 	708 	via
3133 	Intel Atom Z3580 @ 1.33GHz 	707 	intel
3134 	AMD Sempron 150 	707 	AMD
3135 	Intel Pentium T2080 @ 1.73GHz 	707 	intel
3136 	Intel Pentium 5 2.66GHz 	705 	intel
3137 	Intel Atom D525 @ 1.80GHz 	704 	intel
3138 	AMD Opteron 154 	703 	AMD
3139 	Rockchip RK3368 	702 	via
3140 	Intel Core2 Duo U7700 @ 1.33GHz 	700 	intel
3141 	Intel Core Duo T2050 @ 1.60GHz 	694 	intel
3142 	AMD Opteron 254 	693 	AMD
3143 	AC8257V/WAB 	693 	via
3144 	Intel Celeron 925 @ 2.30GHz 	692 	intel
3145 	Intel Celeron G440 @ 1.60GHz 	690 	intel
3146 	AMD Athlon LE-1660 	688 	AMD
3147 	AMD E1-1500 APU 	688 	AMD
3148 	Intel Core2 Duo L7200 @ 1.33GHz 	684 	intel
3149 	Intel Celeron U3405 @ 1.07GHz 	684 	intel
3150 	Intel Xeon MV 3.20GHz 	683 	intel
3151 	Qualcomm MSM8974PRO-AB 	682 	via
3152 	AMD V160 	681 	AMD
3153 	Intel Atom D2550 @ 1.86GHz 	680 	intel
3154 	AMD Athlon 1640B 	678 	AMD
3155 	Intel Celeron 900 @ 2.20GHz 	676 	intel
3156 	MediaTek MT6753 	672 	via
3157 	Intel Core2 Duo U7600 @ 1.20GHz 	664 	intel
3158 	Intel Pentium T2060 @ 1.60GHz 	662 	intel
3159 	AMD Opteron 152 	658 	AMD
3160 	Intel Atom K510 @ 1.66GHz 	658 	intel
3161 	AMD E1-1200 APU 	657 	AMD
3162 	Intel Atom D510 @ 1.66GHz 	657 	intel
3163 	AMD Sempron 130 	656 	AMD
3164 	Samsung EXYNOS5420 	654 	via
3165 	AMD Opteron 250 	649 	AMD
3166 	AMD Athlon 64 FX-53 	646 	AMD
3167 	VIA Nano L3600@2000MHz 	645 	via
3168 	hi6210sft 	645 	via
3169 	AMD Athlon X2 Dual Core L310 	643 	AMD
3170 	Intel Core 330 @ 1.60GHz 	643 	intel
3171 	Intel Pentium D 830 @ 3.00GHz 	642 	intel
3172 	Qualcomm MSM8917 	641 	via
3173 	AMD V140 	641 	AMD
3174 	AMD A4-1200 APU 	638 	AMD
3175 	Qualcomm MSM8974 	638 	via
3176 	MediaTek MT6761V/WBB 	636 	via
3177 	AMD E1-2100 APU 	636 	AMD
3178 	AMD Sempron LE-1620 	635 	AMD
3179 	Rockchip (Device Tree) 	633 	via
3180 	AMD Opteron 246 	632 	AMD
3181 	Qualcomm MSM8974PRO-AA 	629 	via
3182 	Intel Atom N2800 @ 1.86GHz 	628 	intel
3183 	AMD Athlon LE-1640 	627 	AMD
3184 	Intel Celeron 450 @ 2.20GHz 	626 	intel
3185 	ARM Cortex-A72 2 Core 0 MHz 	625 	via
3186 	AMD V120 	623 	AMD
3187 	AMD Athlon II 170u 	623 	AMD
3188 	AMD A4-1250 APU 	618 	AMD
3189 	MT6795MM 	618 	via
3190 	AMD Turion 64 Mobile ML-42 	615 	AMD
3191 	Intel Celeron 827E @ 1.40GHz 	613 	intel
3192 	AMD E-300 APU 	611 	AMD
3193 	AMD Athlon 64 4000+ 	608 	AMD
3194 	AMD Sempron LE-1300 	605 	AMD
3195 	VIA Nano X2 U4025 @ 1.2 GHz 	605 	via
3196 	AMD Opteron 150 	604 	AMD
3197 	Intel Xeon 3.80GHz 	604 	intel
3198 	AMD Opteron 148 	603 	AMD
3199 	Rockchip RK3288 	603 	via
3200 	AMD Athlon 64 3600+ 	601 	AMD
3201 	AMD Athlon 64 3700+ 	599 	AMD
3202 	AMD Turion 64 Mobile ML-44 	591 	AMD
3203 	MediaTek MT6737T 	591 	via
3204 	AMD Athlon 64 3800+ 	590 	AMD
3205 	Intel Core2 Duo Q6867 @ 3.00GHz 	589 	intel
3206 	Intel Atom 330 @ 1.60GHz 	587 	intel
3207 	Intel Celeron D 430 @ 1.80GHz 	585 	intel
3208 	AMD Sempron M120 	582 	AMD
3209 	Intel Core2 Duo U7500 @ 1.06GHz 	582 	intel
3210 	MT8766A 	581 	via
3211 	VIA Nano L3050@1800MHz 	581 	via
3212 	Intel Pentium D 915 @ 2.80GHz 	581 	intel
3213 	Intel Atom E3825 @ 1.33GHz 	579 	intel
3214 	MediaTek MT8168A 	576 	via
3215 	Mobile AMD Athlon 64 4000+ 	576 	AMD
3216 	AMD Athlon 64 3300+ 	576 	AMD
3217 	MT6761V/CAB 	575 	via
3218 	AMD Athlon 64 2200+ 	575 	AMD
3219 	Intel Atom N570 @ 1.66GHz 	574 	intel
3220 	AMD Athlon LE-1620 	572 	AMD
3221 	Mobile AMD Athlon XP 	572 	AMD
3222 	AMD Athlon XP 3400+ 	570 	AMD
3223 	AMD Athlon LE-1600 	567 	AMD
3224 	Qualcomm MSM 8974 HAMMERHEAD (Flattened Device Tre 	566 	via
3225 	Intel Atom Z2760 @ 1.80GHz 	565 	intel
3226 	AMD C-70 APU 	563 	AMD
3227 	MT6761V/WAB 	561 	via
3228 	AMD Athlon II 160u 	560 	AMD
3229 	AMD Sempron M100 	558 	AMD
3230 	Qualcomm Technologies, Inc QM215 	558 	via
3231 	AMD Sempron 3800+ 	554 	AMD
3232 	Intel Celeron 440 @ 2.00GHz 	546 	intel
3233 	ARM Cortex-A53 4 Core 1800 MHz 	545 	via
3234 	AMD Athlon 64 3400+ 	545 	AMD
3235 	AMD C-60 APU 	544 	AMD
3236 	Intel Core Duo U2400 @ 1.06GHz 	544 	intel
3237 	Intel Celeron M 540 @ 1.86GHz 	542 	intel
3238 	AMD Sempron LE-1250 	541 	AMD
3239 	AMD Athlon XP-M 	541 	AMD
3240 	AMD Athlon 64 3500+ 	539 	AMD
3241 	mt6762m 	538 	via
3242 	AMD Turion 64 Mobile MT-40 	536 	AMD
3243 	Intel Celeron 560 @ 2.13GHz 	535 	intel
3244 	AMD Sempron LE-1600 	535 	AMD
3245 	Intel Pentium D 805 @ 2.66GHz 	535 	intel
3246 	AMD Opteron 146 	532 	AMD
3247 	MT6750V/W 	532 	via
3248 	AMD Sempron LE-1200 	528 	AMD
3249 	Intel Atom N2600 @ 1.60GHz 	526 	intel
3250 	AMD Athlon II Neo K145 	525 	AMD
3251 	Intel Atom N550 @ 1.50GHz 	525 	intel
3252 	Intel 2.80GHz 	525 	intel
3253 	AMD Z-01 	523 	AMD
3254 	AMD Turion 64 Mobile ML-40 	522 	AMD
3255 	MT6592 	521 	via
3256 	Intel Celeron 570 @ 2.26GHz 	517 	intel
3257 	VIA Nano L3025@1600MHz 	517 	via
3258 	AMD G-T40N 	516 	AMD
3259 	Intel Celeron 540 @ 1.86GHz 	515 	intel
3260 	Intel Celeron 550 @ 2.00GHz 	515 	intel
3261 	AMD Turion 64 Mobile MK-38 	513 	AMD
3262 	Mobile AMD Athlon XP-M 	512 	AMD
3263 	Intel Core Duo U2500 @ 1.20GHz 	512 	intel
3264 	Mobile AMD Athlon 64 3400+ 	511 	AMD
3265 	Intel Pentium M 2.26GHz 	509 	intel
3266 	Intel Xeon 3.60GHz 	509 	intel
3267 	Mobile AMD Athlon XP-M (LV) 	508 	AMD
3268 	Qualcomm MSM8974PRO-AC 	507 	via
3269 	Intel Pentium M 2.13GHz 	505 	intel
3270 	Mobile AMD Athlon XP-M (LV) 3200+ 	505 	AMD
3271 	AMD Athlon 2850e 	504 	AMD
3272 	VIA Nano U3100 (1.6GHz Capable) 	501 	via
3273 	AMD Z-60 APU 	500 	AMD
3274 	AMD Athlon MP 2800+ 	497 	AMD
3275 	Mobile AMD Athlon MP-M 2800+ 	496 	AMD
3276 	MediaTek MT6739WW 	491 	via
3277 	Intel Xeon 3.06GHz 	491 	intel
3278 	AMD Athlon 64 3200+ 	491 	AMD
3279 	Intel Celeron 430 @ 1.80GHz 	490 	intel
3280 	AMD Sempron LE-250 	490 	AMD
3281 	Intel Atom E3826 @ 1.46GHz 	489 	intel
3282 	Intel Pentium 4 3.60GHz 	488 	intel
3283 	AMD Sempron 3600+ 	487 	AMD
3284 	Mobile AMD Athlon XP-M 3200+ 	487 	AMD
3285 	Intel Pentium 4 3.46GHz 	487 	intel
3286 	AMD Opteron 144 	486 	AMD
3287 	Intel Pentium 4 3.73GHz 	486 	intel
3288 	Mobile AMD Sempron 3800+ 	485 	AMD
3289 	AMD Athlon 3100+ 	485 	AMD
3290 	Intel Pentium 4 3.80GHz 	485 	intel
3291 	AMD Sempron 3300+ 	484 	AMD
3292 	Intel Pentium M 756 @ 1.66GHz 	484 	intel
3293 	AMD Turion 64 Mobile MT-37 	484 	AMD
3294 	AMD Athlon 64 3100+ 	484 	AMD
3295 	Intel Celeron D 420 @ 1.60GHz 	481 	intel
3296 	VIA Eden X2 U4200 @ 1.0+ GHz 	480 	via
3297 	Intel Xeon 3.40GHz 	478 	intel
3298 	Mobile Intel Pentium 4 3.46GHz 	478 	intel
3299 	Rockchip RK3288 (Flattened Device Tree) 	477 	via
3300 	AMD Opteron 248 	476 	AMD
3301 	Mobile AMD Athlon XP-M (LV) 2800+ 	475 	AMD
3302 	AMD Athlon QI-46 	473 	AMD
3303 	Amlogic 	473 	via
3304 	AMD Athlon II Neo K125 	472 	AMD
3305 	Intel Core Solo T1400 @ 1.83GHz 	470 	intel
3306 	MediaTek MT6737M 	468 	via
3307 	Intel Celeron 530 @ 1.73GHz 	468 	intel
3308 	Intel Core2 Solo U3500 @ 1.40GHz 	467 	intel
3309 	AMD G-T40E 	467 	AMD
3310 	AMD C-60 	466 	AMD
3311 	AMD Turion 64 Mobile MK-36 	465 	AMD
3312 	AMD Athlon XP 2300+ 	464 	AMD
3313 	AMD Athlon 64 3000+ 	463 	AMD
3314 	Intel Pentium M 2.00GHz 	462 	intel
3315 	AMD C-50 	462 	AMD
3316 	AMD Athlon 2400+ 	462 	AMD
3317 	Intel Xeon 3.20GHz 	461 	intel
3318 	AMD Athlon 3200+ 	458 	AMD
3319 	Intel Celeron M 530 @ 1.73GHz 	458 	intel
3320 	QCT APQ8064 FLO 	457 	via
3321 	Intel Celeron M 723 @ 1.20GHz 	457 	intel
3322 	VIA Nano L1900@1400MHz 	457 	via
3323 	AMD Sempron 3400+ 	454 	AMD
3324 	AMD Sempron SI-42 	454 	AMD
3325 	Intel Celeron N2805 @ 1.46GHz 	454 	intel
3326 	AMD Sempron 3100+ 	452 	AMD
3327 	Qualcomm Technologies, Inc MSM8917 	452 	via
3328 	Mobile AMD Athlon 64 3000+ 	450 	AMD
3329 	Intel Celeron M 450 @ 2.00GHz 	450 	intel
3330 	Intel Celeron 420 @ 1.60GHz 	449 	intel
3331 	Mobile AMD Athlon 64 3200+ 	448 	AMD
3332 	Intel Pentium M 2.10GHz 	448 	intel
3333 	AMD Athlon 2800+ 	447 	AMD
3334 	SAMSUNG JF 	446 	via
3335 	AMD Sempron LE-1150 	445 	AMD
3336 	Mobile AMD Sempron 3300+ 	445 	AMD
3337 	QCT APQ8064 DEB 	445 	via
3338 	AMD Athlon 2600+ 	444 	AMD
3339 	AMD Sempron SI-40 	443 	AMD
3340 	AMD Turion 64 Mobile ML-37 	442 	AMD
3341 	Mobile AMD Athlon 64 2800+ 	440 	AMD
3342 	AMD Athlon XP 2900+ 	440 	AMD
3343 	Mobile AMD Athlon XP-M 3100+ 	440 	AMD
3344 	Mobile AMD Sempron 3400+ 	440 	AMD
3345 	Mobile Intel Pentium 4 3.33GHz 	439 	intel
3346 	AMD Sempron LE-1100 	438 	AMD
3347 	Intel Pentium M 1.86GHz 	438 	intel
3348 	AMD Athlon 64 2800+ 	438 	AMD
3349 	MediaTek MT6762V/CN 	437 	via
3350 	AMD Athlon 64 FX-51 	437 	AMD
3351 	AMD Athlon MP 2400+ 	436 	AMD
3352 	Sony Mobile fusion3 	436 	via
3353 	Mobile AMD Athlon 64 3700+ 	435 	AMD
3354 	Intel T1200 @ 1.50GHz 	435 	intel
3355 	Intel Xeon 2.66GHz 	435 	intel
3356 	AMD Athlon XP 3100+ 	433 	AMD
3357 	AMD Athlon XP 3200+ 	433 	AMD
3358 	Mobile AMD Sempron 3600+ 	431 	AMD
3359 	Intel Celeron M 520 @ 1.60GHz 	431 	intel
3360 	Generic DT based system 	430 	via
3361 	Qualcomm Technologies, Inc MSM8916 	430 	via
3362 	Intel Celeron 743 @ 1.30GHz 	429 	intel
3363 	AMD Turion 64 Mobile MT-34 	429 	AMD
3364 	AMD Opteron 142 	428 	AMD
3365 	ARM Cortex-A53 4 Core 1400 MHz 	428 	via
3366 	VIA Nano L2100@1800MHz 	428 	via
3367 	AMD Turion 64 Mobile MT-32 	426 	AMD
3368 	AMD Turion 64 Mobile ML-34 	425 	AMD
3369 	AMD Turion 64 Mobile MT-28 	419 	AMD
3370 	Mobile AMD Sempron 3100+ 	416 	AMD
3371 	Samsung GrandPrimePlus LTE LTN OPEN rev04 board ba 	415 	via
3372 	Intel Core2 Solo U3300 @ 1.20GHz 	415 	intel
3373 	AMD Athlon TF-20 	413 	AMD
3374 	Intel Pentium M 1.73GHz 	412 	intel
3375 	AMD Athlon 2100+ 	412 	AMD
3376 	AMD Athlon Neo MV-40 	409 	AMD
3377 	AMD Sempron 3000+ 	409 	AMD
3378 	Intel Pentium M 1.80GHz 	409 	intel
3379 	AMD Athlon 2650e 	409 	AMD
3380 	VIA Nano U3300@1200MHz 	409 	via
3381 	AMD Turion 64 Mobile ML-32 	408 	AMD
3382 	Mobile AMD Sempron 3500+ 	408 	AMD
3383 	ARM Cortex-A53 4 Core 1296 MHz 	408 	via
3384 	AMD Sempron 3200+ 	406 	AMD
3385 	Intel Pentium M 1.70GHz 	406 	intel
3386 	ARM Cortex-A53 4 Core 1512 MHz 	406 	via
3387 	Intel Celeron 723 @ 1.20GHz 	405 	intel
3388 	Intel Pentium SU2700 @ 1.30GHz 	405 	intel
3389 	MT8735P 	405 	via
3390 	Intel Celeron D 365 @ 3.60GHz 	404 	intel
3391 	Intel Atom D2500 @ 1.86GHz 	404 	intel
3392 	AMD-K7 	403 	via
3393 	AMD K7 	403 	AMD
3394 	AMD Turion 64 Mobile ML-30 	402 	AMD
3395 	AMD Athlon XP 3000+ 	402 	AMD
3396 	MT6735P 	401 	via
3397 	AMD Athlon XP2200+ 	401 	AMD
3398 	AMD GX-210JA SOC 	401 	AMD
3399 	Intel Xeon 2.80GHz 	400 	intel
3400 	AMD Geode NX 2400+ 	400 	AMD
3401 	QCT APQ8064 MAKO 	399 	via
3402 	AMD Athlon XP 2800+ 	399 	AMD
3403 	Mobile AMD Athlon 64 2700+ 	398 	AMD
3404 	Intel Celeron M 440 @ 1.86GHz 	397 	intel
3405 	AMD Opteron 140 	396 	AMD
3406 	Intel Core Solo T1350 @ 1.86GHz 	396 	intel
3407 	Intel Pentium 4 3.40GHz 	396 	intel
3408 	Mobile AMD Sempron 2600+ 	394 	AMD
3409 	VIA Esther 2000MHz 	394 	via
3410 	Intel Core Solo T1300 @ 1.66GHz 	393 	intel
3411 	Qualcomm APQ8084 	393 	via
3412 	AMD Athlon XP 2700+ 	393 	AMD
3413 	Intel Celeron M 1.70GHz 	393 	intel
3414 	AMD Sempron 2100+ 	392 	AMD
3415 	AMD Sempron 210U 	391 	AMD
3416 	Intel Xeon 3.00GHz 	391 	intel
3417 	Unisoc SC9832e 	391 	via
3418 	AMD Turion 64 Mobile ML-28 	390 	AMD
3419 	AMD Athlon 2000+ 	390 	AMD
3420 	Mobile AMD Sempron 3000+ 	389 	AMD
3421 	AMD Sempron 2800+ 	383 	AMD
3422 	Intel Atom Z550 @ 2.00GHz 	381 	intel
3423 	AMD Athlon 64 FX-34 	380 	AMD
3424 	AMD Sempron 3500+ 	379 	AMD
3425 	Mobile AMD Athlon MP-M 2000+ 	378 	AMD
3426 	AMD Turion 64 Mobile MT-30 	378 	AMD
3427 	VIA Nano U2250 (1.6GHz Capable) 	377 	via
3428 	Intel Pentium M 1700MHz 	376 	intel
3429 	MT8735 	375 	via
3430 	AMD Athlon XP2400+ 	374 	AMD
3431 	AMD Athlon 2500+ 	374 	AMD
3432 	AMD Athlon 64 2600+ 	374 	AMD
3433 	Intel Pentium 4 3.20GHz 	374 	intel
3434 	AMD Sempron 2600+ 	373 	AMD
3435 	Mobile AMD Athlon XP-M (LV) 2200+ 	373 	AMD
3436 	AMD Athlon XP 2600+ 	372 	AMD
3437 	Mobile AMD Athlon 2500+ 	370 	AMD
3438 	Mobile AMD Athlon XP-M 2600+ 	370 	AMD
3439 	Intel Celeron 807UE @ 1.00GHz 	369 	intel
3440 	VIA Nano L2007@1600MHz 	369 	via
3441 	VIA C7-D 2000MHz 	368 	via
3442 	AMD Athlon XP Pro3+ 	367 	AMD
3443 	Intel Celeron M 430 @ 1.73GHz 	367 	intel
3444 	Intel Pentium M 1.50GHz 	366 	intel
3445 	Mobile AMD Athlon XP-M 2800+ 	365 	AMD
3446 	Mobile AMD Athlon XP-M 3000+ 	365 	AMD
3447 	Intel Celeron M 1.60GHz 	365 	intel
3448 	Intel Pentium M 1.60GHz 	364 	intel
3449 	Mobile AMD Athlon XP-M 2200+ 	364 	AMD
3450 	AMD Athlon 2200+ 	363 	AMD
3451 	MT8765WB 	363 	via
3452 	ARM ARMv7 rev 4 (v7l) 4 Core 1200 MHz 	362 	via
3453 	Manta 	362 	via
3454 	Qualcomm Technologies, Inc MSM8920 	361 	via
3455 	Mobile AMD Sempron 2800+ 	361 	AMD
3456 	AMD Athlon XP 2400+ 	360 	AMD
3457 	AMD Athlon TF-36 	358 	AMD
3458 	Mobile AMD Athlon 4 2400+ 	358 	AMD
3459 	Mobile Intel Pentium 4 3.20GHz 	356 	intel
3460 	AMD Athlon XP 2500+ 	355 	AMD
3461 	MediaTek MT8163 	354 	via
3462 	Intel Pentium M 1500MHz 	354 	intel
3463 	Mobile AMD Sempron 3200+ 	354 	AMD
3464 	AMD Athlon XP1900+ 	353 	AMD
3465 	Intel Pentium 4 3.00GHz 	353 	intel
3466 	VIA Eden C1050@1.06GHz 	352 	via
3467 	Intel Core2 Solo U2100 @ 1.06GHz 	350 	intel
3468 	AMD Athlon 1700+ 	349 	AMD
3469 	Intel Atom Z540 @ 1.86GHz 	348 	intel
3470 	Intel Pentium 4 3.06GHz 	347 	intel
3471 	Qualcomm Technologies, Inc APQ8017 	346 	via
3472 	Mobile AMD Athlon XP-M 2400+ 	346 	AMD
3473 	Mobile AMD Athlon XP-M 2500+ 	346 	AMD
3474 	Intel Atom E680 @ 1.60GHz 	346 	intel
3475 	Intel Pentium M 1.40GHz 	345 	intel
3476 	Intel Atom D425 @ 1.80GHz 	345 	intel
3477 	Qualcomm MSM8928 	344 	via
3478 	AMD Athlon XP 1700 	344 	AMD
3479 	Intel Celeron M 1.50GHz 	343 	intel
3480 	MT6739WA 	343 	via
3481 	MediaTek MT6739WA 	343 	via
3482 	Mobile AMD Athlon XP-M 1900+ 	342 	AMD
3483 	ARM Cortex-A53 4 Core 1152 MHz 	342 	via
3484 	AMD Athlon MP 1700+ 	339 	AMD
3485 	Intel Celeron M 420 @ 1.60GHz 	339 	intel
3486 	ARM Cortex-A7 4 Core 1368 MHz 	337 	via
3487 	Mobile Intel Pentium 4 3.06GHz 	337 	intel
3488 	AMD Sempron 2500+ 	335 	AMD
3489 	Mobile AMD Athlon XP-M (LV) 2000+ 	335 	AMD
3490 	Intel Celeron D 360 @ 3.46GHz 	334 	intel
3491 	Intel Celeron 3.33GHz 	333 	intel
3492 	Qualcomm MSM8228 	332 	via
3493 	Qualcomm Technologies, Inc QCM2150 	332 	via
3494 	Intel Pentium M 1600MHz 	332 	intel
3495 	Intel Celeron M 1500MHz 	332 	intel
3496 	Intel Atom E3815 @ 1.46GHz 	331 	intel
3497 	Intel Core Solo U1500 @ 1.33GHz 	330 	intel
3498 	AMD Athlon XP 2200+ 	328 	AMD
3499 	Intel Celeron M 360 1.40GHz 	327 	intel
3500 	Mobile AMD Athlon XP-M 1700+ 	323 	AMD
3501 	AMD Athlon XP 2100+ 	323 	AMD
3502 	Intel Celeron 215 @ 1.33GHz 	322 	intel
3503 	Intel Pentium M 1400MHz 	321 	intel
3504 	Intel Pentium 4 2.80GHz 	321 	intel
3505 	Intel Celeron 220 @ 1.20GHz 	320 	intel
3506 	AMD Sempron 2300+ 	318 	AMD
3507 	AMD E-240 	318 	AMD
3508 	Intel Celeron M 1.30GHz 	316 	intel
3509 	Intel Celeron D 356 @ 3.33GHz 	315 	intel
3510 	Mobile Intel Pentium 4 2.80GHz 	315 	intel
3511 	Intel Celeron M 410 @ 1.46GHz 	315 	intel
3512 	Mobile AMD Athlon 4 	314 	AMD
3513 	Intel Atom N475 @ 1.83GHz 	314 	intel
3514 	AMD Sempron 2400+ 	313 	AMD
3515 	Mobile Intel Pentium 4 – M 2.60GHz 	313 	intel
3516 	AMD Athlon XP 1900+ 	312 	AMD
3517 	Samsung GrandPrimePlus LTE CIS rev04 board based o 	312 	via
3518 	Intel Core2 Solo U2200 @ 1.20GHz 	311 	intel
3519 	AMD C-30 	310 	AMD
3520 	Intel Pentium III 1266S @ 1266MHz 	309 	intel
3521 	Intel Atom 230 @ 1.60GHz 	307 	intel
3522 	Intel Atom N470 @ 1.83GHz 	307 	intel
3523 	AMD Athlon L110 	306 	AMD
3524 	VIA Nano U2500@1200MHz 	306 	via
3525 	Samsung Exynos 7570 	305 	via
3526 	Intel Atom N2100 @ 1.60GHz 	305 	intel
3527 	MediaTek MT6737 	304 	via
3528 	MediaTek MT6735 	303 	via
3529 	Intel Pentium M 1300MHz 	303 	intel
3530 	Intel Celeron M 1300MHz 	303 	intel
3531 	AMD G-T52R 	303 	AMD
3532 	Intel Celeron 1400MHz 	302 	intel
3533 	Intel Celeron D 352 @ 3.20GHz 	302 	intel
3534 	Intel Pentium M 1.30GHz 	301 	intel
3535 	Intel Atom D410 @ 1.66GHz 	301 	intel
3536 	UNIVERSAL3475 	301 	via
3537 	AMD Athlon XP 1800+ 	300 	AMD
3538 	Mobile AMD Athlon XP-M 2000+ 	300 	AMD
3539 	Intel Pentium III 1400S @ 1400MHz 	299 	intel
3540 	AMD Athlon XP 2000+ 	299 	AMD
3541 	AMD V105 	299 	AMD
3542 	Intel Pentium 4 2.93GHz 	299 	intel
3543 	Intel Pentium M 1.20GHz 	298 	intel
3544 	Intel Pentium III 1400 @ 1400MHz 	297 	intel
3545 	Unisoc SC7731e 	297 	via
3546 	Mobile AMD Athlon XP-M 1800+ 	297 	AMD
3547 	Intel Atom N450 @ 1.66GHz 	297 	intel
3548 	Mobile AMD Athlon XP-M (LV) 1600+ 	296 	AMD
3549 	VIA Nano L2207@1600MHz 	296 	via
3550 	Mobile AMD Athlon MP-M 2400+ 	295 	AMD
3551 	Qualcomm MSM8926 	294 	via
3552 	AMD Athlon 1500+ 	294 	AMD
3553 	Mobile Intel Celeron 1200MHz 	294 	intel
3554 	Qualcomm MSM8626 	294 	via
3555 	Qualcomm Technologies, Inc MSM8216 	292 	via
3556 	Qualcomm APQ8026 	291 	via
3557 	AMD Geode NX 1750 	291 	AMD
3558 	Intel Celeron 1333MHz 	290 	intel
3559 	Mobile Intel Pentium III – M 1133MHz 	289 	intel
3560 	Mobile Intel Pentium III – M 1333MHz 	289 	intel
3561 	Qualcomm Technologies, Inc APQ8009 	289 	via
3562 	686 Gen 	288 	via
3563 	Intel Celeron 1300MHz 	288 	intel
3564 	Intel Celeron 3.20GHz 	288 	intel
3565 	Mobile AMD Athlon XP-M (LV) 1500+ 	288 	AMD
3566 	Spreadtrum SC7731e 	288 	via
3567 	Intel Pentium 4 2.60GHz 	288 	intel
3568 	AMD Athlon 7850 Dual-Core 2.8G 	288 	AMD
3569 	AMD Athlon XP2100+ 	287 	AMD
3570 	Qualcomm Technologies, Inc MSM8909 	287 	via
3571 	VIA C7-D 1500MHz 	287 	via
3572 	Qualcomm Technologies, Inc APQ8016 	286 	via
3573 	Intel Celeron 3.06GHz 	285 	intel
3574 	ARM Cortex-A53 4 Core 0 MHz 	285 	via
3575 	Intel Pentium III 1133 @ 1133MHz 	284 	intel
3576 	VIA C7 1500MHz 	284 	via
3577 	Intel Atom N455 @ 1.66GHz 	284 	intel
3578 	Intel Celeron 2.93GHz 	283 	intel
3579 	Intel Atom N280 @ 1.66GHz 	283 	intel
3580 	Intel Celeron 1133MHz 	282 	intel
3581 	MediaTek MT8735B 	282 	via
3582 	Intel Pentium M 1.10GHz 	282 	intel
3583 	AMD Athlon XP 1500 	282 	AMD
3584 	Intel Atom Z530 @ 1.60GHz 	281 	intel
3585 	AMD Sempron 2200+ 	281 	AMD
3586 	AMD Athlon XP1600+ 	281 	AMD
3587 	Mobile Intel Celeron 2.50GHz 	281 	intel
3588 	Mobile Intel Celeron 1333MHz 	280 	intel
3589 	AMD Athlon 4 	279 	AMD
3590 	Mobile Intel Pentium 4 2.66GHz 	279 	intel
3591 	Intel Core Solo U1400 @ 1.20GHz 	278 	intel
3592 	Intel Pentium III 1200 @ 1200MHz 	278 	intel
3593 	Mobile Intel Pentium 4 2.30GHz 	278 	intel
3594 	ARM Cortex-A7 4 Core 1200 MHz 	277 	via
3595 	Intel Xeon 2.40GHz 	276 	intel
3596 	Intel Celeron M 1200MHz 	275 	intel
3597 	VIA Nano U3500@1000MHz 	275 	via
3598 	VIA Nano U2250@1300+MHz 	274 	via
3599 	Intel Core Solo U1300 @ 1.06GHz 	271 	intel
3600 	AMD Athlon XP 1700+ 	271 	AMD
3601 	Intel Atom E660 @ 1.30GHz 	271 	intel
3602 	Intel Celeron D 347 @ 3.06GHz 	270 	intel
3603 	Intel Atom N270 @ 1.60GHz 	268 	intel
3604 	AMD Sempron 200U 	267 	AMD
3605 	AMD Athlon XP 1600+ 	267 	AMD
3606 	Mobile AMD Athlon 1400+ 	266 	AMD
3607 	Mobile AMD Athlon MP-M 1800+ 	265 	AMD
3608 	Qualcomm MSM8226 	265 	via
3609 	Mobile Intel Pentium 4 2.40GHz 	264 	intel
3610 	AMD Geode NX 	264 	AMD
3611 	Mobile AMD Athlon XP-M 1500+ 	261 	AMD
3612 	Intel Atom N435 @ 1.33GHz 	261 	intel
3613 	Intel Celeron 1066MHz 	259 	intel
3614 	Intel Pentium M 1100MHz 	259 	intel
3615 	AMD Athlon XP 1500+ 	257 	AMD
3616 	Mobile AMD Athlon XP-M 1600+ 	257 	AMD
3617 	Mobile Intel Pentium 4 – M 2.50GHz 	256 	intel
3618 	QCT APQ8064 AWIFI 	256 	via
3619 	Intel Celeron 2.80GHz 	254 	intel
3620 	Intel Pentium 4 2.66GHz 	254 	intel
3621 	Intel Celeron M 443 @ 1.20GHz 	253 	intel
3622 	msm8960dt 	252 	via
3623 	Mobile AMD Sempron 2100+ 	252 	AMD
3624 	Intel XEON 2.20GHz 	252 	intel
3625 	Intel Pentium III Mobile 1133MHz 	251 	intel
3626 	Intel Celeron 2.66GHz 	250 	intel
3627 	Mobile Intel Pentium III – M 1000MHz 	250 	intel
3628 	VIA Esther 1300MHz 	250 	via
3629 	Intel Pentium 4 2.53GHz 	248 	intel
3630 	Intel Celeron 2.50GHz 	247 	intel
3631 	Intel Pentium III Mobile 1066MHz 	246 	intel
3632 	Intel Celeron 2.53GHz 	245 	intel
3633 	Intel Celeron 2.70GHz 	245 	intel
3634 	Intel Pentium III Mobile 1000MHz 	245 	intel
3635 	Intel Pentium 4 2.50GHz 	245 	intel
3636 	Intel Celeron 1200MHz 	244 	intel
3637 	Intel Celeron 2.10GHz 	244 	intel
3638 	Intel Atom Z670 @ 1.50GHz 	243 	intel
3639 	Intel Pentium III Mobile 1200MHz 	243 	intel
3640 	MediaTek MT8167B 	239 	via
3641 	Mobile Intel Celeron 2.40GHz 	239 	intel
3642 	Intel Celeron 2.60GHz 	238 	intel
3643 	Intel Pentium III 933S @ 933MHz 	238 	intel
3644 	SAMSUNG SERRANO 	238 	via
3645 	Intel Pentium M 1200MHz 	237 	intel
3646 	AMD Athlon XP1700+ 	234 	AMD
3647 	Intel Pentium M 1000MHz 	233 	intel
3648 	Intel Xeon 2.00GHz 	233 	intel
3649 	ARM Cortex-A7 4 Core 900 MHz 	233 	via
3650 	Rockchip RK3328 	232 	via
3651 	Mobile Intel Pentium 4 – M 1.90GHz 	232 	intel
3652 	AMD Athlon MP 	230 	AMD
3653 	Intel Pentium 4 2.40GHz 	228 	intel
3654 	Intel Celeron 2.30GHz 	227 	intel
3655 	AMD G-T44R 	227 	AMD
3656 	MT6735M 	226 	via
3657 	Mobile Intel Celeron 2.20GHz 	226 	intel
3658 	Mobile Intel Pentium III – M 1200MHz 	224 	intel
3659 	Intel Celeron 2.26GHz 	223 	intel
3660 	VIA C7-M 6300MHz 	222 	via
3661 	Intel Pentium 4 2.26GHz 	221 	intel
3662 	VIA Esther 1500MHz 	219 	via
3663 	Intel Atom Z515 @ 1.20GHz 	218 	intel
3664 	Intel Pentium III Mobile 933MHz 	218 	intel
3665 	Intel Celeron 2.40GHz 	217 	intel
3666 	Intel Pentium M 900MHz 	217 	intel
3667 	Intel Atom Z520 @ 1.33GHz 	215 	intel
3668 	Intel Celeron 1000MHz 	213 	intel
3669 	Intel Celeron 2.20GHz 	213 	intel
3670 	Mobile Intel Pentium 4 – M 2.40GHz 	213 	intel
3671 	Mobile Intel Pentium III – M 866MHz 	211 	intel
3672 	Intel Pentium 4 2.20GHz 	210 	intel
3673 	Intel Pentium 4 Mobile 1.90GHz 	209 	intel
3674 	Intel Celeron 2.13GHz 	208 	intel
3675 	Intel Pentium 4 Mobile 1.70GHz 	208 	intel
3676 	Intel Celeron M 1.00GHz 	207 	intel
3677 	Rockchip RK3326 	204 	via
3678 	Mobile Intel Celeron 2.00GHz 	204 	intel
3679 	Intel Celeron M 900MHz 	204 	intel
3680 	VIA C7-D 1800MHz 	203 	via
3681 	AMD G-T40R 	203 	AMD
3682 	Mobile Intel Pentium 4 – M 2.00GHz 	202 	intel
3683 	Intel Pentium 4 Mobile 2.00GHz 	202 	intel
3684 	Mobile Intel Pentium III – M 933MHz 	200 	intel
3685 	Mobile Intel Pentium 4 – M 2.20GHz 	198 	intel
3686 	Intel Pentium 4 Mobile 1.50GHz 	197 	intel
3687 	Mobile Intel Pentium 4 – M 1.60GHz 	195 	intel
3688 	Intel Pentium 4 3.83GHz 	195 	intel
3689 	Intel Atom Z510 @ 1.10GHz 	194 	intel
3690 	Intel Xeon 1500MHz 	193 	intel
3691 	Intel Pentium 4 1600MHz 	193 	intel
3692 	Rockchip RK3229 	191 	via
3693 	Intel Pentium 4 2.00GHz 	189 	intel
3694 	ARM Cortex-A53 4 Core 1536 MHz 	188 	via
3695 	Mobile Intel Celeron 1.50GHz 	188 	intel
3696 	Mobile Intel Celeron 1.60GHz 	188 	intel
3697 	Intel Celeron B710 @ 1.60GHz 	186 	intel
3698 	Mobile Intel Celeron 1.80GHz 	186 	intel
3699 	Intel Celeron 2.00GHz 	185 	intel
3700 	Mobile AMD Athlon XP-M 1400+ 	184 	AMD
3701 	Intel Celeron M ULV 800MHz 	184 	intel
3702 	Intel Pentium 4 4.00GHz 	184 	intel
3703 	Intel Pentium III Mobile 800MHz 	182 	intel
3704 	Mobile Intel Celeron 1.70GHz 	181 	intel
3705 	VIA C7-M 1600MHz 	178 	via
3706 	Intel Pentium 4 Mobile 1.60GHz 	178 	intel
3707 	Mobile Intel Pentium 4 – M 1.80GHz 	175 	intel
3708 	Intel Pentium 4 Mobile 1.80GHz 	175 	intel
3709 	Intel Celeron 1100MHz 	174 	intel
3710 	Mobile Intel Pentium 4 – M 1.70GHz 	173 	intel
3711 	Mobile Intel Celeron 1.20GHz 	170 	intel
3712 	ARM Cortex-A53 4 Core 1200 MHz 	166 	via
3713 	Intel Pentium 4 1.40GHz 	164 	intel
3714 	VIA C7-M 1000MHz 	164 	via
3715 	Intel Pentium 4 1800MHz 	162 	intel
3716 	Intel Pentium 4 1.80GHz 	160 	intel
3717 	Intel Pentium 4 1.90GHz 	159 	intel
3718 	VIA Eden 800MHz 	155 	via
3719 	VIA Nehemiah 	155 	via
3720 	Intel Pentium 4 1700MHz 	154 	intel
3721 	Intel Pentium III Mobile 866MHz 	152 	intel
3722 	Intel Celeron M 600MHz 	151 	intel
3723 	Intel Pentium 4 Mobile 1.40GHz 	149 	intel
3724 	Intel Celeron 600MHz 	147 	intel
3725 	VIA Esther 1000MHz 	146 	via
3726 	ARM Cortex-A7 2 Core 1080 MHz 	142 	via
3727 	VIA Eden 1200MHz 	142 	via
3728 	VIA C7-M 1200MHz 	140 	via
3729 	Intel Celeron 1.80GHz 	136 	intel
3730 	Intel Pentium 4 1.70GHz 	132 	intel
3731 	Intel Pentium 4 1.50GHz 	131 	intel
3732 	Intel Celeron 1.70GHz 	130 	intel
3733 	Intel Pentium 4 1.60GHz 	129 	intel
3734 	Intel Pentium 4 1400MHz 	127 	intel
3735 	Intel Pentium 4 1500MHz 	125 	intel
3736 	VIA Eden 1000MHz 	123 	via
3737 	Intel Pentium 4 1300MHz 	119 	intel
3738 	AMD Athlon 64 2000+ 	116 	AMD
3739 	AMD-K6-III 	108 	via
3740 	Intel Pentium III Mobile 750MHz 	103 	intel
3741 	VIA C3 Ezra 	100 	via
3742 	AMD-K6 3D 	90 	via
3743 	VIA Samuel 2 	79 	via
3744 	ARM Cortex-A7 2 Core 960 MHz 	72 





谁是处理器之王？不是看核心数量能堆多少，也不是看频率多高，而是看核心效率（IPC）。在酷睿11代与锐龙5000系列（ZEN3）的较量中，英特尔稳住了移动版领域，但在桌面版之中小输对手。

蝉联多年金腰带的拳王，赢，则理所当然，输，则舆论哗然。

英特尔也如同这位拳王，一时间众说纷纭，有的哀叹廉颇老矣，有的嘲笑牙膏挤完了。谁会想到，其卧薪尝胆，暗练神功，在短时间就夺回金腰带。

酷睿12代比11代，在数字上只是一小步，但在X86处理器领域上是一大步，由此进入了大小核混合架构新时代！

酷睿12代处理器进入混合架构

正文

酷睿12代出生后就注定不平凡。四大亮点——

在工艺上，从14nm直接升级到Intel 7，总算摘掉了万年14纳米的帽子，来到了10nm时代，虽然晶体管密度领先于台积电7nm，但10这个数字看起来不太帅，听起来要比7nm差不少。英特尔决定改名，将10nm Enhanced SuperFin工艺改称“intel 7”（没有nm），后续的7nm工艺则会改名为Intel 4。

在架构上，采用全新的性能核（P-Core）和能效核（E-Core）混合架构设计。也就是说，酷睿12代是个混血儿，他的P核流淌着纯正的酷睿血液，而E核隶属于Atom（凌动）家族。这样设计的目的，是让P核提供足够强的单核性能，而用E核以较低的功耗提升多线程性能。下文我们将看到，这样的设计带来了惊人的性能提升。

在特性上，首次支持DDR5内存和PCI-E 5.0。

在表现上，i5首次在部分测试中打败上代i9，在极速空间CPU天梯图排序中，出现了二者战平的奇迹。

首批次发布了6款处理器，分别是：

i9-12900K（KF）

i7-12700K（KF）

i5-12600K（KF）

i9-12900K 、i7-12700K、i5-12600K参数对比

 酷睿十二代是“革命性的进步”，它不仅拥有制程和微架构双升级，能耗比也如同火箭一般提升。

从i9-12900K和i9-11900K的对比，可以看出端倪。（下图）

 i9-12900K 和i9-11900K 对比

i9-12900K只用241W功耗，就比i9-11900K（250W）多线程性能高50%，当功耗降低到125W，其性能还要高30%，当性能降低和酷睿i9-11900K（250W）相同的时候，酷睿i9-12900K只需要65W功耗。

注：从酷睿十二代开始，不再称为TDP，分为基础功耗（PL1）和最大睿频功耗（PL2），K系列处理器默认PL1=PL2。

 到底性能如何？直接上图。

 极速空间CPU性能天梯图（2021含酷睿12代）

CPU天梯图怎么看（位置等高时，对比核心数量和线程，少则胜）

有些初学者可能会想，吹了半天，酷睿十二代还是不如锐龙三代，英特尔这边的性能值都低于2000。

原因：这是以多核性能为主导（并考虑单核性能）的综合排序，英特尔的32、64核的产品都在服务器端，目前还没有下放到X系列，由于在发烧级平台的竞争中核心数量落后，以至于在天梯图里的位置偏低。

判断CPU性能的三个层次——

初学者仅看其位置高低。

有一定经验的用户，会把多核和单核性能结合起来。

资深用户，会首先看CPU核心效率天梯图，其次再看多核和单核性能排名。

当然，如果只看上图，还有一个简便办法，即：位置等高对比其核心数量和线程。

例如：i7-12700K和R7-5900X位置相同，前者8P+4E合计12核，20线程，后者12核24线程，核心相同线程数量落后，能达到综合性能持平，说明IPC更高。（注：这里为简化起见，未考虑频率差异）




