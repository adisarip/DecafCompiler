; ModuleID = 'Decaf'
source_filename = "Decaf"

@0 = private unnamed_addr constant [28 x i8] c"Fibonacci Series for N=%d: \00"
@1 = private unnamed_addr constant [4 x i8] c"%d \00"

define void @main() {
Start:
  %cnt = alloca i32
  %next = alloca i32
  %curr = alloca i32
  %prev = alloca i32
  %N = alloca i32
  store i32 0, i32* %N
  store i32 0, i32* %prev
  store i32 0, i32* %curr
  store i32 0, i32* %next
  %0 = load i32, i32* %prev
  store i32 0, i32* %prev
  %1 = load i32, i32* %curr
  store i32 1, i32* %curr
  %2 = load i32, i32* %next
  store i32 1, i32* %next
  %3 = load i32, i32* %N
  store i32 10, i32* %N
  %4 = load i32, i32* %N
  %5 = call i32 @printf(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @0, i32 0, i32 0), i32 %4)
  store i32 0, i32* %cnt
  br label %Loop

Loop:                                             ; preds = %Loop, %Start
  %cnt1 = phi i32 [ 0, %Start ], [ %NextValue, %Loop ]
  %6 = load i32, i32* %N
  %7 = load i32, i32* %curr
  %8 = call i32 @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %7)
  %9 = load i32, i32* %curr
  %10 = load i32, i32* %prev
  store i32 %9, i32* %prev
  %11 = load i32, i32* %next
  %12 = load i32, i32* %curr
  store i32 %11, i32* %curr
  %13 = load i32, i32* %prev
  %14 = load i32, i32* %curr
  %ADD = add i32 %13, %14
  %15 = load i32, i32* %next
  store i32 %ADD, i32* %next
  %cnt2 = load i32, i32* %cnt
  %NextValue = add i32 %cnt2, 1
  store i32 %NextValue, i32* %cnt
  %LoopCondition = icmp slt i32 %NextValue, %6
  br i1 %LoopCondition, label %Loop, label %AfterLoop

AfterLoop:                                        ; preds = %Loop
  ret void
}

declare i32 @printf(i8*, i32)
