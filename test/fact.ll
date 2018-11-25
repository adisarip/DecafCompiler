; ModuleID = 'Decaf'
source_filename = "Decaf"

@0 = private unnamed_addr constant [24 x i8] c"Factorial of %d is: %d \00"

define void @main() {
Start:
  %i = alloca i32
  %factN = alloca i32
  %N = alloca i32
  store i32 0, i32* %N
  store i32 0, i32* %factN
  %0 = load i32, i32* %N
  store i32 6, i32* %N
  %1 = load i32, i32* %factN
  store i32 1, i32* %factN
  %2 = load i32, i32* %N
  %CEQ = icmp eq i32 %2, 0
  br i1 %CEQ, label %If, label %Else

If:                                               ; preds = %Start
  %3 = load i32, i32* %factN
  store i32 1, i32* %factN
  br label %IfNext

Else:                                             ; preds = %Start
  store i32 1, i32* %i
  br label %Loop

Loop:                                             ; preds = %Loop, %Else
  %i1 = phi i32 [ 1, %Else ], [ %NextValue, %Loop ]
  %4 = load i32, i32* %N
  %ADD = add i32 %4, 1
  %5 = load i32, i32* %factN
  %6 = load i32, i32* %i
  %MUL = mul i32 %5, %6
  %7 = load i32, i32* %factN
  store i32 %MUL, i32* %factN
  %i2 = load i32, i32* %i
  %NextValue = add i32 %i2, 1
  store i32 %NextValue, i32* %i
  %LoopCondition = icmp slt i32 %NextValue, %ADD
  br i1 %LoopCondition, label %Loop, label %AfterLoop

AfterLoop:                                        ; preds = %Loop
  br label %IfNext

IfNext:                                           ; preds = %AfterLoop, %If
  %8 = load i32, i32* %N
  %9 = load i32, i32* %factN
  %10 = call i32 @printf(i8* getelementptr inbounds ([24 x i8], [24 x i8]* @0, i32 0, i32 0), i32 %8, i32 %9)
  ret void
}

declare i32 @printf(i8*, i32, i32)
