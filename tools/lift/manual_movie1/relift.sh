#!/bin/sh
# Re-lift movie1 batch off+enforce. Run from recomp/tools/lift with outdir arg.
set -e
OUT=$1
mkdir -p $OUT
LIFTDIR=.
python3 ./lift.py manual_movie1/a5c5.snip $OUT/a5c5_off.c b6 entry_A5C2,entry_A5C5,LA5DB,LA5EE,LA5F2 entry_A605 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/a5c5.snip $OUT/a5c5_enf.c b6 entry_A5C2,entry_A5C5,LA5DB,LA5EE,LA5F2 entry_A605 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b4a.snip $OUT/b4a_off.c b4 entry_B02F,entry_B032,entry_B040,entry_B041,entry_B044,entry_AFF6,entry_AFFF entry_B004,entry_B009,entry_B054 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b4a.snip $OUT/b4a_enf.c b4 entry_B02F,entry_B032,entry_B040,entry_B041,entry_B044,entry_AFF6,entry_AFFF entry_B004,entry_B009,entry_B054 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6b.snip $OUT/b6b_off.c b6 entry_8B74,entry_8B77,entry_8BE5,entry_8C00,L8C08,L8C0A entry_8B8A,entry_8C32,entry_8C4D ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6b.snip $OUT/b6b_enf.c b6 entry_8B74,entry_8B77,entry_8BE5,entry_8C00,L8C08,L8C0A entry_8B8A,entry_8C32,entry_8C4D ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6c.snip $OUT/b6c_off.c b6 entry_AFFC,entry_AFFF,entry_B012 entry_A2E9 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6c.snip $OUT/b6c_enf.c b6 entry_AFFC,entry_AFFF,entry_B012 entry_A2E9 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6d.snip $OUT/b6d_off.c b6 entry_B013,entry_B016,LB02E,LB047 entry_B04B ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6d.snip $OUT/b6d_enf.c b6 entry_B013,entry_B016,LB02E,LB047 entry_B04B ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6e.snip $OUT/b6e_off.c b6 entry_9FDA,entry_9FDD,entry_9FF8 entry_9FF8x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6e.snip $OUT/b6e_enf.c b6 entry_9FDA,entry_9FDD,entry_9FF8 entry_9FF8x ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6f.snip $OUT/b6f_off.c b6 entry_9FF9,entry_9FFC,entry_A029,entry_A02F,entry_A032,entry_A046,entry_A047,entry_A04A,entry_A083,entry_A089,entry_A08C,entry_A0B5,LA03F,LA097,LA0AB entry_9B81,entry_9E9E,entry_A009,entry_A063 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6f.snip $OUT/b6f_enf.c b6 entry_9FF9,entry_9FFC,entry_A029,entry_A02F,entry_A032,entry_A046,entry_A047,entry_A04A,entry_A083,entry_A089,entry_A08C,entry_A0B5,LA03F,LA097,LA0AB entry_9B81,entry_9E9E,entry_A009,entry_A063 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6g.snip $OUT/b6g_off.c b6 entry_B3E3,entry_B3E6,entry_B3FD "" ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6g.snip $OUT/b6g_enf.c b6 entry_B3E3,entry_B3E6,entry_B3FD "" ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
python3 ./lift.py manual_movie1/b6h.snip $OUT/b6h_off.c b6 entry_B3FE,entry_B401 entry_B457 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6h.snip $OUT/b6h_enf.c b6 entry_B3FE,entry_B401 entry_B457 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
echo done
python3 ./lift.py manual_movie1/b6i.snip $OUT/b6i_off.c b6 entry_9BAA entry_9BB1 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:off
python3 ./lift.py manual_movie1/b6i.snip $OUT/b6i_enf.c b6 entry_9BAA entry_9BB1 ADDRMAP:./ADDRMAP.txt PROV:./PROV_ALL.txt JMPTAB:./JMPTAB.txt VEC:./vec007A.txt UNWIND:enforce
