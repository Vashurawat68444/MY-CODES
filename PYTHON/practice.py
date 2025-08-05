#https://docs.google.com/document/d/1CuKacG3lnnt5B-7kB9p1DiJ2PLFW8TQWn9JG1lTYRJs/edit?usp=sharing
# link for questions and solution are save in my phone by you tube video.

# 1.
# age1,age2,age3 = int(input("age1 : ")),int(input("age2 : ")),int(input("age3 : "))
# if(age1>age2 and age1>age3):
#     print("maximum age is :  ",age1)
# elif(age2>age3):
#     print("maximum age is :",age2)
# else:
#     print("maximum age is : ",age3)

#2.
# celcius = int(input("ENTER TEMPRATURE IN CELSIUS : "))
# print("TEMPRATURE IN FARENHITE : ",[(celcius * 9/5) + 32])

#3.
# num1 = int(input("ENTER NUMBER 1 : "))
# num2 = int(input("ENTER NUMBER 2 : "))
# temp = num1
# num1 = num2
# num2 = temp
# print("NOW NUMBER 1 AND NUMBER 2 : ",num1  , num2)

#4.
# a,b,c = int(input("dig1 : ")),int(input("dig2 : ")),int(input("dig3 : "))
# print("SUM IS : ",a+b+c)

#5.
  # method 1
  # number = list(input("YOUR INPUT IS : "))
  # print(number) 
  # number.reverse()
  # print(number)
  # number.append(0)
  # print(number)
  # method 2
  # length = -len(number)
  # print(length)
  # i = -1
  # while i >= length:
  #     print(number[i],"")
  #     i-=1

#6.
# num = int(input("ENTER YOUR INPUT : "))
# if num%2 == 0:
#     print("NUMBER IS EVEN")
# else:
#     print("NUMBER IS ODD")

#7.
# year = int(input("ENTER YEAR : "))
# if year%4 == 0:
#     print("THIS YEAR IS LEAP YEAR")
# else:
#     print("THIS IS NOT LEAP YEAR")

#8.
# import math
# x1,y1 = int(input("X1 : ")),int(input("Y1 : "))
# x2,y2 = int(input("X2 : ")),int(input("Y2 : "))
# print("ECLUDIAN DISTANCE IS : ",math.sqrt(pow(x1-x2,2) + pow(y1-y2,2)))

#9.
# angel1,angel2,angel3 = float(input("Angle 1 : ")),float(input("Angle 2 : ")),float(input("Angle 3 : "))
# if angel1+angel2+angel3 == 180.0:
#     print("it is an triangle")
# else:
#     print("it is not an triangle")

#10.
# cost,price = int(input("cost : ")),int(input("price : "))
# if cost >= price:
#     print("loss")
# else:
#     print("profit")

#11.
# principle_amount = int(input("ENTER PRNCIPLE AMOUNT : "))
# rate_of_intrest = int(input("ENTER RATE OF INTREST : "))
# time_period = int(input("ENTER TIME PERIOD : "))
# print("SIMPLE INTREST : ",(principle_amount*rate_of_intrest*time_period)/100)

#12.
# radius = int(input("ENTER RADIUS : "))
# volume = 3.14*radius*radius
# print("VOLUME IS : ",volume)
# print("MILK IN LETER IS : ",volume*40)

#13.
# num = int(input("ENTER YOUR INPUT : "))
# if num%6 == 0 and num%3 == 0:
#     print("NUMBER IS DIVISBLE BY 3 & 6 ")
# else:
#     print("NUMBER IS NOT DIVISIBLE")

#14.
# hour = float(input("ENTER YOUR HOURS : "))
# minutes = float(input("ENTER MINUTES : "))
# angle_by_hours = (hour*5*6 + minutes*0.5)
# angle_by_minutes = (minutes*6)
# if angle_by_hours>angle_by_minutes:
#     diff = angle_by_hours - angle_by_minutes
# else:
#     diff = angle_by_minutes - angle_by_hours
# if diff>180:
#     print("YOUR ANGLE DIFFERENCE IS : ",360-diff)
# else:
#     print("YOUT ANGLE DIFFERENCE IS : ",diff)

#16.
# L1x,L1y = int(input("ENTER X CORDINATE FOR L1 : ")),int(input("ENTER Y CORDINATE FOR L1 : "))
# R1x,R1y = int(input("ENTER X CORDINATE FOR R1 : ")),int(input("ENTER Y CORDINATE FOR R1 : "))
# L2x,L2y = int(input("ENTER X CORDINATE FOR L2 : ")),int(input("ENTER Y CORDINATE FOR L2 : "))
# R2x,R2y = int(input("ENTER X CORDINATE FOR R2 : ")),int(input("ENTER Y CORDINATE FOR R2 : "))
# length_rec1 = R1x-L1x
# breth_rec1 = L1y-R1y
# if length_rec1+R1x>L2x and breth_rec1+R1y>R2y:
#     flag = 1 

#18.
# import math
# number = input("ENTER YOUR INPUT : ")
# digit_list = list(number)
# power = int(digit_list[len(digit_list)-1])
# temp = 0
# i=0
# while i<len(digit_list):
#     num = int(digit_list[i])
#     temp  = temp + pow(num,power)
#     i+=1
# newnumber = temp
# number = int(number)
# if newnumber == number:
#     print("IT IS AN ARMSTRONG NUMBER")
# else:
#     print("IT IS NOT AN ARMSTRONG NUMBER")

#20.
# salery = int(input("ENTER YOUR SALERY IN LAKS : "))
# HRA = salery*0.1
# DA = salery*0.15
# PF = salery*0.03
# if salery >= 0 and salery<5:
#     salery = salery - HRA - DA -PF
# elif salery>=5 and salery<=10:
#     salery = salery - HRA -DA -PF -0.1*salery
# elif salery>=11 and salery<=20:
#     salery = salery - HRA - DA - PF - 0.2*salery
# elif salery>20:
#     salery = salery-HRA-DA-PF-0.3*salery
# print("YOUR NET SALERY IS : ",salery)

#22.
# head,legs = int(input("ENTER HEADS : ")),int(input("ENTER LEGS : "))
# dogs,chicken = 0,0
# if legs%head == 0:
#     if head*4 == legs:
#         dogs = head
#     elif head*2 == legs:
#         chicken = head
# else :

#28.
# num = int(input("ENTER YOUR INPUT : "))
# FLAG = 0
# if num>3 or num<-3:
#     for i in range(2,num-1):
#       if num%i ==0:
#           FLAG = 0
#           break
#       else:
#           FLAG = 1
# else:
#     FLAG = 0
# if FLAG == 0:
#     print("IT IS NOT A PRIME NUMBER")
# else:
#     print("IT IS A PRIME NUMBER")

#29.
# import math
# for i in range(100,3000):
#     list_of_digit = list(str(i))
#     length = len(list_of_digit)
#     power = int(list_of_digit[length-1])
#     temp = 0
#     for k in range(0,length):
#         temp = temp + pow(int(list_of_digit[k]),power)
#         if temp == i:
#             print(i)

#30.
# present_population = int(input("ENTER YOUR POPULATION : "))
# temp = present_population
# print("POPULATION IN 10TH YEAR : ",present_population)
# for i in range(9,0,-1):
#     temp = temp - temp*0.1
#     print("POPULATION IN ",i,"TH", "YEAR : ",int(temp))

#31.
# number = list(input("ENTER YOUR NUMBER : "))
# temp = number
# for el in range(len(number)):
#     i=0
#     j=i+1
#     while i<len(number)-1:
#         r = temp[i]
#         temp[i]=temp[j]
#         temp[j]=r 
#         io = i
#         jo = j 
#         tempo = temp
#         print(temp)
#         i=0
#         j=2
#         r1=temp[i]
#         temp[i]=temp[j]
#         temp[j]=r1
#         print(temp)
#         i=io+1
#         j=jo+1
#         temp = tempo

#33.
# num1 = float(input("NUMBER 1 : "))
# num2 = float(input("NUMBER 2 : "))
# o_num1 = num1
# o_num2 = num2
# list_of_common_factor = []
# common_factor = 2
# lcm = 1
# while num1 != 1 or num2 != 1:
#     if num1%common_factor==0 and num2%common_factor==0:
#         list_of_common_factor.append(common_factor)
#         num1 = num1/common_factor
#         num2 = num2/common_factor
#     elif num1%common_factor==0 or num2%common_factor==0:
#         if num1%common_factor==0:
#             list_of_common_factor.append(common_factor)
#             num1 = num1/common_factor
#         elif num2%common_factor==0:
#             list_of_common_factor.append(common_factor)
#             num2 = num2/common_factor
#     else:
#         common_factor+=1
# print("list of common factors between ",o_num1,"and",o_num2,":",list_of_common_factor)
# for i in range(len(list_of_common_factor)):
#     lcm = lcm*list_of_common_factor[i]
# print("YOUR LCM IS : ",lcm)
        
#34
# list_of_prime_number = [1,2,3]
# for i in range(4,26):
#     flag=0
#     number = i
#     for j in range(2,number):
#         if number%j==0:
#             break
#         else:
#             flag=1
#     if(flag==1):
#         list_of_prime_number.append(number)
# print(list_of_prime_number)
# for i in range(len(list_of_prime_number)):
#     print(list_of_prime_number[i])

#37
# import math
# value = int(input("enter your input : "))
# print(value + pow(value,2) + pow(value,3))

#38
# value = int(input("enter your input : "))
# i=10
# count=0 
# while(value%i!=0):
#     count+=1
#     value = int(value/i)
# print(count)

#39.
# import math
# value = (input("enter your input : "))
# li = list(value)
# li.reverse()
# temp=0
# for i in range(len(li)):
#     temp = temp + int(li[i])*pow(10,len(li)-1-i)
# print("your reverse is : ",temp)
# # checking palundrome or not 
# if value == temp:
#     print("palindrome")
# else:
#     print("not palindrome")

#41.
# num = int(input("enter number of lines : "))
# for i in range(1,num+1):
#     for k in range(1,i+1):
#         print("*",end="") #here end is used for printing in same line 
#     print("\n")

#42.
# line = int(input("ENTER LINE WHERE YOU WANT TO SEE MAXIMUM STAR : "))
# for i in range(1,line+1):
#     for k in range(1,i+1):
#         print("*",end="") #here end is used for printing in same line 
#     print("\n")
# for i in range(line-1,0,-1):
#     for k in range(i,0,-1):
#         print("*",end="")
#     print("\n")

#43.
# line = int(input("ENTER THE NUMBER OF LINES : "))
# for i in range(1,line+1):
#     for k in range(0,line-i):
#         print(" ",end="")
#     for k in range(1,2*i):
#         print("*",end="")
#     print("\n")

#44.
# lines = int(input("ENTER YOUR INPUT : "))
# for i in range(1,lines+1):
#     for k in range(1,i+1):
#         print(k,end="")
#     for k in range(i-1,0,-1):
#         print(k,end="")
#     print("\n")

#45.
# lines = int(input('ENTER LINES : '))
# for_print =  1
# for i in range(1,lines+1):
#     k=0
#     while k<i:
#         print(for_print," ",end="")
#         k+=1
#         for_print+=1
#     print("\n")

#46.
# import math
# def factorial(number):
#     if number==1:
#         return number
#     else:
#         return number*factorial(number-1)
    

# num = int(input("ENTER YOUT NUMBER : "))
# sum = 0
# for i in range(1,num+1):
#     sum = sum + num/factorial(num)

# print("YOUR SUM IS : ",sum)

#47.
# import math
# x,n = int(input("ENTER X : ")),int(input("ENTER N : "))
# sum = 1
# for i in range(2,n+1):
#     sum = sum + pow(x,i)/i

# print("YOUR SUM IS : ",sum)  

#48.
# import math
# x = int(input("ENTER X : "))
# for_cal = (x-1)/x
# sum = 0
# for i in range(1,8):
#     sum = sum + pow(for_cal,i)/i

# print("YOUR SUM IS : ",sum)

#49.
# sum = 0
# avg = 0
# i=1
# number = int(input("ENTER NUMBER : "))
# while number!=0:
#     sum +=number
#     avg = sum/i
#     print("MY AVERAGE AND SUM IS : ",sum," ",avg)
#     number = int(input("ENTER NUMBER : "))
#     i+=1

#50.
# numerator = int(input("ENTER YOUR NUMERATOR : "))
# denominator = int(input("ENTER YOUR DEMONIATOR : "))
# factor = 2
# while (factor<=numerator or factor<=denominator):
#     if numerator%factor==0 and denominator%factor==0:
#         numerator = numerator/factor
#         denominator = denominator/factor
#     else:
#         factor+=1
# print(int(numerator),"/",int(denominator))

#51.
# var = str(input("ENTER YOUT STRING : "))
# count = 0 
# for i in var:
#     count+=1

#52.
# email = str(input("ENTER YOUR EMAIL : "))
# i=0
# while email[i]!='@':
#     i+=1
# j=0
# print("YOUR USER NAME : ",end="")
# while j<i:
#     print(email[j],end="")
#     j+=1

#57.
# list1 = ['a','d','s','d']
# list2 = ['d','s','d','a']
# print(list1 == list2)
# var = str(input("ENTER YOUR INPUT : "))
# list1 = list(var)
# print("list1 : ",list1)
# list2 = list1
# list2.reverse()
# print("list2 : ",list2)
# print(type(list1),type(list2))
# print(list1==list2)
# if list1 == list2:
#     print("IT IS PALINDROME")
# else:
#     print("IT IS NOT PALINDROME")

#58.
list1 = [2,6,9,3,5,2,3,6,5,9]
x = int(input("ENTER YOUR INPUT : "))
length = len(list1)
i=0
while i<length:
    
