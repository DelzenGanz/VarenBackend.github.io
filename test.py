import calendar

yy = int(input('What year?: '))
mm = int(input('What month?: '))

if yy <= 2999 and mm <= 12 :
    print(calendar.month(yy, mm))
elif yy >= 2999 and mm <= 12 :
    print("year invalid")
elif mm >= 12 and yy <= 2999 :
    print("Month invalid")
else :
    print("Year and month invalid")

