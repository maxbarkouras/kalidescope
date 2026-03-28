define i32 @main(){
entry:
    %1 = call i32 @square(i32 15)
    ret i32 %1
}

define void @do_nothing(){
    ret void
}

define void @do_not_call(){
    unreachable
}

define i32 @square(i32 %x) {
    %1 = mul i32 %x, %x
    ret i32 %1
}

define i32 @add(i32 %x) {
    %2 = add i32 %x, %x
    ret i32 %2
}

define i64 @safe_divide(i64 %n, i64 %d) {
    %1 = icmp eq i64 %d, 0 
    br i1 %1, label %nonzero, label %zero

nonzero:
    ret i64 -1

zero:
    %2 = udiv i64 %n, %d
    ret i64 %2
}