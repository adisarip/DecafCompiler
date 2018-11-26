; ModuleID = 'Decaf'
source_filename = "Decaf"

@testData = global [100 x i32] zeroinitializer
@0 = private unnamed_addr constant [11 x i8] c"TestData: \00"
@1 = private unnamed_addr constant [4 x i8] c"%d \00"
@2 = private unnamed_addr constant [5 x i8] c" || \00"
@3 = private unnamed_addr constant [21 x i8] c"Searching for %d || \00"
@4 = private unnamed_addr constant [28 x i8] c"Found %d at location %d !!!\00"

define void @main() {
Start:
  %i12 = alloca i32
  %i4 = alloca i32
  %i1 = alloca i32
  %breakFlag = alloca i32
  %middle = alloca i32
  %last = alloca i32
  %first = alloca i32
  %N = alloca i32
  %searchValue = alloca i32
  %num = alloca i32
  %i = alloca i32
  store i32 0, i32* %i
  store i32 0, i32* %num
  store i32 0, i32* %searchValue
  store i32 0, i32* %N
  store i32 0, i32* %first
  store i32 0, i32* %last
  store i32 0, i32* %middle
  store i32 0, i32* %breakFlag
  %0 = load i32, i32* %N
  store i32 10, i32* %N
  %1 = load i32, i32* %searchValue
  store i32 14, i32* %searchValue
  store i32 0, i32* %i1
  br label %Loop

Loop:                                             ; preds = %Loop, %Start
  %i2 = phi i32 [ 0, %Start ], [ %NextValue, %Loop ]
  %2 = load i32, i32* %N
  %3 = load i32, i32* %i1
  %MUL = mul i32 %3, 2
  %4 = load i32, i32* %i1
  %testData_idx = getelementptr [100 x i32], [100 x i32]* @testData, i32 0, i32 %4
  %5 = load i32, i32* %testData_idx
  store i32 %MUL, i32* %testData_idx
  %i3 = load i32, i32* %i1
  %NextValue = add i32 %i3, 1
  store i32 %NextValue, i32* %i1
  %LoopCondition = icmp slt i32 %NextValue, %2
  br i1 %LoopCondition, label %Loop, label %AfterLoop

AfterLoop:                                        ; preds = %Loop
  %6 = call i32 @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @0, i32 0, i32 0))
  store i32 0, i32* %i4
  br label %Loop5

Loop5:                                            ; preds = %Loop5, %AfterLoop
  %i7 = phi i32 [ 0, %AfterLoop ], [ %NextValue10, %Loop5 ]
  %7 = load i32, i32* %N
  %8 = load i32, i32* %i4
  %testData_idx8 = getelementptr [100 x i32], [100 x i32]* @testData, i32 0, i32 %8
  %9 = load i32, i32* %testData_idx8
  %10 = call i32 bitcast (i32 (i8*)* @printf to i32 (i8*, i32)*)(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %9)
  %i9 = load i32, i32* %i4
  %NextValue10 = add i32 %i9, 1
  store i32 %NextValue10, i32* %i4
  %LoopCondition11 = icmp slt i32 %NextValue10, %7
  br i1 %LoopCondition11, label %Loop5, label %AfterLoop6

AfterLoop6:                                       ; preds = %Loop5
  %11 = call i32 @printf(i8* getelementptr inbounds ([5 x i8], [5 x i8]* @2, i32 0, i32 0))
  %12 = load i32, i32* %first
  store i32 0, i32* %first
  %13 = load i32, i32* %N
  %SUB = sub i32 %13, 1
  %14 = load i32, i32* %last
  store i32 %SUB, i32* %last
  %15 = load i32, i32* %first
  %16 = load i32, i32* %last
  %ADD = add i32 %15, %16
  %DIV = sdiv i32 %ADD, 2
  %17 = load i32, i32* %middle
  store i32 %DIV, i32* %middle
  %18 = load i32, i32* %breakFlag
  store i32 0, i32* %breakFlag
  %19 = load i32, i32* %searchValue
  %20 = call i32 bitcast (i32 (i8*)* @printf to i32 (i8*, i32)*)(i8* getelementptr inbounds ([21 x i8], [21 x i8]* @3, i32 0, i32 0), i32 %19)
  %21 = load i32, i32* %first
  store i32 %21, i32* %i12
  br label %Loop13

Loop13:                                           ; preds = %IfNext31, %AfterLoop6
  %i15 = phi i32 [ %21, %AfterLoop6 ], [ %NextValue33, %IfNext31 ]
  %22 = load i32, i32* %last
  %ADD16 = add i32 %22, 1
  %23 = load i32, i32* %middle
  %testData_idx17 = getelementptr [100 x i32], [100 x i32]* @testData, i32 0, i32 %23
  %24 = load i32, i32* %testData_idx17
  %25 = load i32, i32* %searchValue
  %CLT = icmp slt i32 %24, %25
  br i1 %CLT, label %If, label %Else

AfterLoop14:                                      ; preds = %IfNext31
  ret void

If:                                               ; preds = %Loop13
  %26 = load i32, i32* %middle
  %ADD18 = add i32 %26, 1
  %27 = load i32, i32* %first
  store i32 %ADD18, i32* %first
  br label %IfNext24

Else:                                             ; preds = %Loop13
  %28 = load i32, i32* %middle
  %testData_idx19 = getelementptr [100 x i32], [100 x i32]* @testData, i32 0, i32 %28
  %29 = load i32, i32* %testData_idx19
  %30 = load i32, i32* %searchValue
  %CEQ = icmp eq i32 %29, %30
  br i1 %CEQ, label %If20, label %Else22

If20:                                             ; preds = %Else
  %31 = load i32, i32* %searchValue
  %32 = load i32, i32* %middle
  %ADD21 = add i32 %32, 1
  %33 = call i32 bitcast (i32 (i8*)* @printf to i32 (i8*, i32, i32)*)(i8* getelementptr inbounds ([28 x i8], [28 x i8]* @4, i32 0, i32 0), i32 %31, i32 %ADD21)
  %34 = load i32, i32* %breakFlag
  store i32 1, i32* %breakFlag
  br label %IfNext

Else22:                                           ; preds = %Else
  %35 = load i32, i32* %middle
  %SUB23 = sub i32 %35, 1
  %36 = load i32, i32* %last
  store i32 %SUB23, i32* %last
  br label %IfNext

IfNext:                                           ; preds = %Else22, %If20
  br label %IfNext24

IfNext24:                                         ; preds = %IfNext, %If
  %37 = load i32, i32* %first
  %38 = load i32, i32* %last
  %ADD25 = add i32 %37, %38
  %DIV26 = sdiv i32 %ADD25, 2
  %39 = load i32, i32* %middle
  store i32 %DIV26, i32* %middle
  %40 = load i32, i32* %breakFlag
  %CEQ27 = icmp eq i32 %40, 1
  br i1 %CEQ27, label %If28, label %Else29

If28:                                             ; preds = %IfNext24
  %41 = load i32, i32* %last
  %42 = load i32, i32* %i12
  store i32 %41, i32* %i12
  br label %IfNext31

Else29:                                           ; preds = %IfNext24
  %43 = load i32, i32* %first
  %SUB30 = sub i32 %43, 1
  %44 = load i32, i32* %i12
  store i32 %SUB30, i32* %i12
  br label %IfNext31

IfNext31:                                         ; preds = %Else29, %If28
  %i32 = load i32, i32* %i12
  %NextValue33 = add i32 %i32, 1
  store i32 %NextValue33, i32* %i12
  %LoopCondition34 = icmp slt i32 %NextValue33, %ADD16
  br i1 %LoopCondition34, label %Loop13, label %AfterLoop14
}

declare i32 @printf(i8*)
