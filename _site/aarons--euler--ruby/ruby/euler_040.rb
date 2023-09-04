# An irrational decimal fraction is created by concatenating the positive integers:
#
# 0.123456789101112131415161718192021...
#
# It can be seen that the 12th digit of the fractional part is 1.
#
# If dn represents the nth digit of the fractional part, find the value of the following expression.
#
# d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000


# first 10 digits are size 1
# next 89 digits are size 2
# next 900 digits are size 3
# next 9000 digits are size 4

# 1.upto(2000) { |n| num += n.to_s }

# number at positions on number line increase more slowly than normal, depending
# on position...

number_string = ""

185186.times do |i|
  number_string += i.to_s
end

multiply = [1,10,100,1000,10000,100000,1000000]

product = 1

multiply.each do |i|
  puts "#{i} = #{number_string[i].chr.to_i}"
  product *= number_string[i].chr.to_i
end

puts product

# 1 = 1
# 10 = 1
# 100 = 5
# 1000 = 3
# 10000 = 7
# 100000 = 2
# 1000000 = 1
# product == 210


=begin a python solution, ran in 0.6 second
s = ""
l = len(s)
x,next,prev,sum = 1,1,0,1
while l < 1000000:
s = str(x);
l += len( str(x) )
if l >= next:
sum *= int( s[next - prev - 1 ])
next = next*10
prev = l
x += 1
print sum
=end

=begin c++ implementation from md2perpe

#include <iostream&gt;
#include <stdlib.h&gt;
using namespace std;

inline
int digit2num(char digit)
{
	return digit-'0';
}

inline
int digitOfNum(int index, int num)
{
	char buf[10];
	sprintf(buf, "%d", num);
	return digit2num(buf[index]);
}

int decimal(int index)
{
	int firstindex = 0;
	int numcount = 9;
	int firstnum = 1;
	for(int numlen=1; numlen<10; numlen++) {
		int groupindex = (index-firstindex)/numlen;
		if( groupindex < numcount ) {
			return digitOfNum((index-firstindex)%numlen, firstnum+groupindex);
		}

		firstindex += numlen*numcount;

		firstnum *= 10;
		numcount *= 10;
	}
}

int main(int argc, char *argv[])
{
	int prod = 1;
	for(int pos=1; pos<=1000000; pos*=10)
		prod *= decimal(pos-1);

	cout << prod << endl;

	system("PAUSE");
	return 0;
}
=end

=begin java
public class Fraction {

    public Fraction() {
    }

    int[] digitsPerDecade = new int[6];


    public int getAnswer(){
        fillDigitsPerDecade();
        int product = digit(1) * digit(10) * digit(100) * digit(1000) *
          digit(10000) * digit(100000) * digit(1000000);
        return product;
    }

    private void fillDigitsPerDecade(){
        digitsPerDecade[0] = 9;
        digitsPerDecade[1] = 90*2;
        digitsPerDecade[2] = 900*3;
        digitsPerDecade[3] = 9000*4;
        digitsPerDecade[4] = 90000*5;
        digitsPerDecade[5] = 900000*6;
    }

    private int digit(int n){
        int i = 0;
        int base = 1;
        int digitsPerNumber = 1;
        while (n > digitsPerDecade[i]) {
            n -= digitsPerDecade[i++];
            base *= 10;
            digitsPerNumber++;
        }
        int numberOrder = (n-1) / digitsPerNumber + 1;
        int digitOrder = (n-1) % digitsPerNumber;
        int number = base + numberOrder - 1;
        String rep = String.valueOf(number);
        return digitVal(rep.charAt(digitOrder));
    }

    private int digitVal(char ch){
        return (int) ch - (int) '0';
    }

    public static void main(String[] args){
        Fraction f = new Fraction();
        long start = System.currentTimeMillis();
        int answer = f.getAnswer();
        long stop = System.currentTimeMillis();
        System.out.println("Answer: " + answer);
        System.out.println("Time used: " + (stop-start) + "ms");
    }

}
=end
