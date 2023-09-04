from django.shorcuts import render

def add(a,b):
 return a+b

def mul(a,b):
 return a*b

def sub(a,b):
 return a-b

def operation(request):
  if 'sym' in request.GET:
        if request.GET['sym'] == 'add':
            first=request.GET['result']
            opsign='\&plus;'
            return render(request,'calculator.html',{'result':first,'prev_val':first,'curr_val':second,'opsign':opsign})
  elif request.GET['sym'] == '=':
        if 'prev_val' in request.GET and request.GET['prev_val']:
            first=request.GET['prev_val']
        if 'result' in request.GET and request.GET['result']:
            second=request.GET['result']
        try:
            result=add(10,20)
        except ValueError:
            err="Error: Incorrect Number"
        except ZeroDivisionError:
            err="Error: Division by zero"
        return render(request,'calculator.html',{'result':result,'error':err})
    else:
        return render(request,'calculator.html',{'error':'No Operation selected'})
