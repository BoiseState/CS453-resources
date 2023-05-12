(define_insn "*add<mode>3_aarch64"
  [(set
    (match_operand:GPI 0 "register_operand" "=rk,rk,w,rk,r,rk")
    (plus:GPI
     (match_operand:GPI 1 "register_operand" "%rk,rk,w,rk,rk,rk")
     (match_operand:GPI 2 "aarch64_pluslong_operand" "I,r,w,J,Uaa,Uav")))]
  ""
  "@
  add\\t%<w>0, %<w>1, %2
  add\\t%<w>0, %<w>1, %<w>2
  add\\t%<rtn>0<vas>, %<rtn>1<vas>, %<rtn>2<vas>
  sub\\t%<w>0, %<w>1, #%n2
  #
  * return aarch64_output_sve_addvl_addpl (operands[0], operands[1], operands[2]);"
  ;; The "alu_imm" type for ADDVL/ADDPL is just a placeholder.
  [(set_attr "type" "alu_imm,alu_sreg,neon_add,alu_imm,multiple,alu_imm")
   (set_attr "arch" "*,*,simd,*,*,*")]
)
