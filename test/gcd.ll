; ModuleID = 'Decaf'
source_filename = "Decaf"

@0 = private unnamed_addr constant [26 x i8] c"gcd of %d and %d is: %d  \00"

define i32 @gcd(i32 %x, i32 %y) {
Start:
  %y2 = alloca i32
  %x1 = alloca i32
  store i32 %x, i32* %x1
  store i32 %y, i32* %y2
  %0 = load i32, i32* %x1
  %1 = load i32, i32* %y2
  %CEQ = icmp eq i32 %0, %1
  br i1 %CEQ, label %If, label %Else

If:                                               ; preds = %Start
  %2 = load i32, i32* %x1
  ret i32 %2

Else:                                             ; preds = %Start
  %3 = load i32, i32* %x1
  %4 = load i32, i32* %y2
  %CLT = icmp slt i32 %3, %4
  br i1 %CLT, label %If3, label %Else4

If3:                                              ; preds = %Else
  %5 = load i32, i32* %x1
  %6 = load i32, i32* %y2
  %7 = load i32, i32* %x1
  %SUB = sub i32 %6, %7
  %8 = call i32 @gcd(i32 %SUB, i32 %5)
  ret i32 %8

Else4:                                            ; preds = %Else
  %9 = load i32, i32* %x1
  %10 = load i32, i32* %y2
  %SUB5 = sub i32 %9, %10
  %11 = load i32, i32* %y2
  %12 = call i32 @gcd(i32 %11, i32 %SUB5)
  ret i32 %12

IfNext:                                           ; No predecessors!
  ret i32 0

IfNext6:                                          ; No predecessors!
  ret i32 0
  ret i32 0
  ret i32 0
}

define void @main() {
Start:
  %b = alloca i32
  %a = alloca i32
  %g = alloca i32
  store i32 0, i32* %g
  store i32 0, i32* %a
  store i32 0, i32* %b
  %0 = load i32, i32* %g
  store i32 0, i32* %g
  %1 = load i32, i32* %a
  store i32 64, i32* %a
  %2 = load i32, i32* %b
  store i32 120, i32* %b
  %3 = load i32, i32* %a
  %4 = load i32, i32* %b
  %5 = call i32 @gcd(i32 %4, i32 %3)
  %6 = load i32, i32* %g
  store i32 %5, i32* %g
  %7 = load i32, i32* %a
  %8 = load i32, i32* %b
  %9 = load i32, i32* %g
  %10 = call i32 @printf(i8* getelementptr inbounds ([26 x i8], [26 x i8]* @0, i32 0, i32 0), i32 %7, i32 %8, i32 %9)
  ret void
}

declare i32 @printf(i8*, i32, i32, i32)
