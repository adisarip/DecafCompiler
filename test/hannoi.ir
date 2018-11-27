; ModuleID = 'Decaf'
source_filename = "Decaf"

@0 = private unnamed_addr constant [38 x i8] c"# Move disk 1 from rod %d to rod %d #\00"
@1 = private unnamed_addr constant [39 x i8] c"# Move disk %d from rod %d to rod %d #\00"

define void @towerOfHanoi(i32 %n, i32 %from_rod, i32 %to_rod, i32 %aux_rod) {
Start:
  %aux_rod4 = alloca i32
  %to_rod3 = alloca i32
  %from_rod2 = alloca i32
  %n1 = alloca i32
  store i32 %n, i32* %n1
  store i32 %from_rod, i32* %from_rod2
  store i32 %to_rod, i32* %to_rod3
  store i32 %aux_rod, i32* %aux_rod4
  %0 = load i32, i32* %n1
  %CEQ = icmp eq i32 %0, 1
  br i1 %CEQ, label %If, label %Else

If:                                               ; preds = %Start
  %1 = load i32, i32* %from_rod2
  %2 = load i32, i32* %to_rod3
  %3 = call i32 @printf(i8* getelementptr inbounds ([38 x i8], [38 x i8]* @0, i32 0, i32 0), i32 %1, i32 %2)
  br label %IfNext

Else:                                             ; preds = %Start
  %4 = load i32, i32* %n1
  %SUB = sub i32 %4, 1
  %5 = load i32, i32* %from_rod2
  %6 = load i32, i32* %aux_rod4
  %7 = load i32, i32* %to_rod3
  call void @towerOfHanoi(i32 %7, i32 %6, i32 %5, i32 %SUB)
  %8 = load i32, i32* %n1
  %9 = load i32, i32* %from_rod2
  %10 = load i32, i32* %to_rod3
  %11 = call i32 bitcast (i32 (i8*, i32, i32)* @printf to i32 (i8*, i32, i32, i32)*)(i8* getelementptr inbounds ([39 x i8], [39 x i8]* @1, i32 0, i32 0), i32 %8, i32 %9, i32 %10)
  %12 = load i32, i32* %n1
  %SUB5 = sub i32 %12, 1
  %13 = load i32, i32* %aux_rod4
  %14 = load i32, i32* %to_rod3
  %15 = load i32, i32* %from_rod2
  call void @towerOfHanoi(i32 %15, i32 %14, i32 %13, i32 %SUB5)
  br label %IfNext

IfNext:                                           ; preds = %Else, %If
  ret void
}

declare i32 @printf(i8*, i32, i32)

define void @main() {
Start:
  %n = alloca i32
  store i32 0, i32* %n
  %0 = load i32, i32* %n
  store i32 4, i32* %n
  %1 = load i32, i32* %n
  call void @towerOfHanoi(i32 3, i32 2, i32 1, i32 %1)
  ret void
}
