
# Should I stall or inject a bubble into Pipeline Register F?
# At most one of these can be true. bool F_bubble = 0;
bool F_stall =
	 		 # Stall if either operand source is destination of
			 # instruction in execute, memory, or write-back stages
			 d_srcA != RNONE && d_srcA in
			   { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE } ||
			 d_srcB != RNONE && d_srcB in
			   { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE } ||
			 # Stalling at fetch while ret passes through pipeline
			 IRET in { D_icode, E_icode, M_icode };
			 
# Should I stall or inject a bubble into Pipeline Register D? # At most one of these can be true.
bool D_stall =
	 		 # Stall if either operand source is destination of
			 # instruction in execute, memory, or write-back stages
			 # but not part of mispredicted branch
			 !(E_icode == IJXX && !e_Bch) &&
			  (d_srcA != RNONE && d_srcA in
			     { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE } ||
			   d_srcB != RNONE && d_srcB in
			     { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE });

bool D_bubble =
        	 # Mispredicted branch
			 (E_icode == IJXX && !e_Bch) ||
			 # Stalling at fetch while ret passes through pipeline
			 !(E_icode in { IMRMOVL, IPOPL } && E_dstM in { d_srcA, d_srcB }) &&
			 # but not condition for a generate/use hazard
			 !(d_srcA != RNONE && d_srcA in
			    { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE } || d_srcB != RNONE && d_srcB in
				{ E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE }) && IRET in { D_icode, E_icode, M_icode };


# Should I stall or inject a bubble into Pipeline Register E?
# At most one of these can be true.
bool E_stall = 0;
bool E_bubble =
	 		  # Mispredicted branch
			  (E_icode == IJXX && !e_Bch) ||
			  # Inject bubble if either operand source is destination of
			  # instruction in execute, memory, or write back stages
			  d_srcA != RNONE &&
              		d_srcA in { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE } ||
              d_srcB != RNONE &&
              		d_srcB in { E_dstM, E_dstE, M_dstM, M_dstE, W_dstM, W_dstE };
# Should I stall or inject a bubble into Pipeline Register M?
