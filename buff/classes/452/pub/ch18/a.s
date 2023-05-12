
a:     file format elf64-x86-64


Disassembly of section .init:

0000000000401000 <_init>:
  401000:	f3 0f 1e fa          	endbr64 
  401004:	48 83 ec 08          	sub    $0x8,%rsp
  401008:	48 8b 05 e9 2f 00 00 	mov    0x2fe9(%rip),%rax        # 403ff8 <__gmon_start__>
  40100f:	48 85 c0             	test   %rax,%rax
  401012:	74 02                	je     401016 <_init+0x16>
  401014:	ff d0                	callq  *%rax
  401016:	48 83 c4 08          	add    $0x8,%rsp
  40101a:	c3                   	retq   

Disassembly of section .text:

0000000000401020 <_start>:
  401020:	f3 0f 1e fa          	endbr64 
  401024:	31 ed                	xor    %ebp,%ebp
  401026:	49 89 d1             	mov    %rdx,%r9
  401029:	5e                   	pop    %rsi
  40102a:	48 89 e2             	mov    %rsp,%rdx
  40102d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
  401031:	50                   	push   %rax
  401032:	54                   	push   %rsp
  401033:	49 c7 c0 c0 11 40 00 	mov    $0x4011c0,%r8
  40103a:	48 c7 c1 50 11 40 00 	mov    $0x401150,%rcx
  401041:	48 c7 c7 06 11 40 00 	mov    $0x401106,%rdi
  401048:	ff 15 a2 2f 00 00    	callq  *0x2fa2(%rip)        # 403ff0 <__libc_start_main@GLIBC_2.2.5>
  40104e:	f4                   	hlt    

000000000040104f <.annobin_init.c>:
  40104f:	90                   	nop

0000000000401050 <_dl_relocate_static_pie>:
  401050:	f3 0f 1e fa          	endbr64 
  401054:	c3                   	retq   

0000000000401055 <.annobin__dl_relocate_static_pie.end>:
  401055:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40105c:	00 00 00 
  40105f:	90                   	nop

0000000000401060 <deregister_tm_clones>:
  401060:	b8 20 40 40 00       	mov    $0x404020,%eax
  401065:	48 3d 20 40 40 00    	cmp    $0x404020,%rax
  40106b:	74 13                	je     401080 <deregister_tm_clones+0x20>
  40106d:	b8 00 00 00 00       	mov    $0x0,%eax
  401072:	48 85 c0             	test   %rax,%rax
  401075:	74 09                	je     401080 <deregister_tm_clones+0x20>
  401077:	bf 20 40 40 00       	mov    $0x404020,%edi
  40107c:	ff e0                	jmpq   *%rax
  40107e:	66 90                	xchg   %ax,%ax
  401080:	c3                   	retq   
  401081:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  401088:	00 00 00 00 
  40108c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401090 <register_tm_clones>:
  401090:	be 20 40 40 00       	mov    $0x404020,%esi
  401095:	48 81 ee 20 40 40 00 	sub    $0x404020,%rsi
  40109c:	48 89 f0             	mov    %rsi,%rax
  40109f:	48 c1 ee 3f          	shr    $0x3f,%rsi
  4010a3:	48 c1 f8 03          	sar    $0x3,%rax
  4010a7:	48 01 c6             	add    %rax,%rsi
  4010aa:	48 d1 fe             	sar    %rsi
  4010ad:	74 11                	je     4010c0 <register_tm_clones+0x30>
  4010af:	b8 00 00 00 00       	mov    $0x0,%eax
  4010b4:	48 85 c0             	test   %rax,%rax
  4010b7:	74 07                	je     4010c0 <register_tm_clones+0x30>
  4010b9:	bf 20 40 40 00       	mov    $0x404020,%edi
  4010be:	ff e0                	jmpq   *%rax
  4010c0:	c3                   	retq   
  4010c1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010c8:	00 00 00 00 
  4010cc:	0f 1f 40 00          	nopl   0x0(%rax)

00000000004010d0 <__do_global_dtors_aux>:
  4010d0:	f3 0f 1e fa          	endbr64 
  4010d4:	80 3d 45 2f 00 00 00 	cmpb   $0x0,0x2f45(%rip)        # 404020 <__TMC_END__>
  4010db:	75 13                	jne    4010f0 <__do_global_dtors_aux+0x20>
  4010dd:	55                   	push   %rbp
  4010de:	48 89 e5             	mov    %rsp,%rbp
  4010e1:	e8 7a ff ff ff       	callq  401060 <deregister_tm_clones>
  4010e6:	c6 05 33 2f 00 00 01 	movb   $0x1,0x2f33(%rip)        # 404020 <__TMC_END__>
  4010ed:	5d                   	pop    %rbp
  4010ee:	c3                   	retq   
  4010ef:	90                   	nop
  4010f0:	c3                   	retq   
  4010f1:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4010f8:	00 00 00 00 
  4010fc:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000401100 <frame_dummy>:
  401100:	f3 0f 1e fa          	endbr64 
  401104:	eb 8a                	jmp    401090 <register_tm_clones>

0000000000401106 <main>:
// gcc -o a -g a.c ; objdump -dS a > a.od
// gcc -c a.c -Wa,-adhlns=a.l -fverbose-asm

int i,a[10];

int main() {
  401106:	55                   	push   %rbp
  401107:	48 89 e5             	mov    %rsp,%rbp
  for (i=0; i<10; i++)
  40110a:	c7 05 2c 2f 00 00 00 	movl   $0x0,0x2f2c(%rip)        # 404040 <i>
  401111:	00 00 00 
  401114:	eb 22                	jmp    401138 <main+0x32>
    a[i]=0;
  401116:	8b 05 24 2f 00 00    	mov    0x2f24(%rip),%eax        # 404040 <i>
  40111c:	48 98                	cltq   
  40111e:	c7 04 85 60 40 40 00 	movl   $0x0,0x404060(,%rax,4)
  401125:	00 00 00 00 
  for (i=0; i<10; i++)
  401129:	8b 05 11 2f 00 00    	mov    0x2f11(%rip),%eax        # 404040 <i>
  40112f:	83 c0 01             	add    $0x1,%eax
  401132:	89 05 08 2f 00 00    	mov    %eax,0x2f08(%rip)        # 404040 <i>
  401138:	8b 05 02 2f 00 00    	mov    0x2f02(%rip),%eax        # 404040 <i>
  40113e:	83 f8 09             	cmp    $0x9,%eax
  401141:	7e d3                	jle    401116 <main+0x10>
  401143:	b8 00 00 00 00       	mov    $0x0,%eax
}
  401148:	5d                   	pop    %rbp
  401149:	c3                   	retq   
  40114a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000401150 <__libc_csu_init>:
  401150:	f3 0f 1e fa          	endbr64 
  401154:	41 57                	push   %r15
  401156:	4c 8d 3d f3 2c 00 00 	lea    0x2cf3(%rip),%r15        # 403e50 <__frame_dummy_init_array_entry>
  40115d:	41 56                	push   %r14
  40115f:	49 89 d6             	mov    %rdx,%r14
  401162:	41 55                	push   %r13
  401164:	49 89 f5             	mov    %rsi,%r13
  401167:	41 54                	push   %r12
  401169:	41 89 fc             	mov    %edi,%r12d
  40116c:	55                   	push   %rbp
  40116d:	48 8d 2d e4 2c 00 00 	lea    0x2ce4(%rip),%rbp        # 403e58 <__do_global_dtors_aux_fini_array_entry>
  401174:	53                   	push   %rbx
  401175:	4c 29 fd             	sub    %r15,%rbp
  401178:	48 83 ec 08          	sub    $0x8,%rsp
  40117c:	e8 7f fe ff ff       	callq  401000 <_init>
  401181:	48 c1 fd 03          	sar    $0x3,%rbp
  401185:	74 1f                	je     4011a6 <__libc_csu_init+0x56>
  401187:	31 db                	xor    %ebx,%ebx
  401189:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401190:	4c 89 f2             	mov    %r14,%rdx
  401193:	4c 89 ee             	mov    %r13,%rsi
  401196:	44 89 e7             	mov    %r12d,%edi
  401199:	41 ff 14 df          	callq  *(%r15,%rbx,8)
  40119d:	48 83 c3 01          	add    $0x1,%rbx
  4011a1:	48 39 dd             	cmp    %rbx,%rbp
  4011a4:	75 ea                	jne    401190 <__libc_csu_init+0x40>
  4011a6:	48 83 c4 08          	add    $0x8,%rsp
  4011aa:	5b                   	pop    %rbx
  4011ab:	5d                   	pop    %rbp
  4011ac:	41 5c                	pop    %r12
  4011ae:	41 5d                	pop    %r13
  4011b0:	41 5e                	pop    %r14
  4011b2:	41 5f                	pop    %r15
  4011b4:	c3                   	retq   
  4011b5:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  4011bc:	00 00 00 00 

00000000004011c0 <__libc_csu_fini>:
  4011c0:	f3 0f 1e fa          	endbr64 
  4011c4:	c3                   	retq   

Disassembly of section .fini:

00000000004011c8 <_fini>:
  4011c8:	f3 0f 1e fa          	endbr64 
  4011cc:	48 83 ec 08          	sub    $0x8,%rsp
  4011d0:	48 83 c4 08          	add    $0x8,%rsp
  4011d4:	c3                   	retq   
