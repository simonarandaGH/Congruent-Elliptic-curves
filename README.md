Description of some of the topics addressed.

Elliptic curves C[n], the Weierstrass short normal form [-n^2,0].

Tunnell's Theorem. Implementation of the Criteria. Definition of the function r(n) and conjectures about this function.

The form XYW(n) and the form PQRS(n) which allow us to obtain the usual right triangles of area n. And also provide points on the elliptic curves C[n] and the two Surfaces. The form GNP(n).

The "xrank" program.  Which implements all the above points and complements them with various algebraic, algorithmic and computational aspects.

<math display = 'block'>
  <mtable columnalign='left' linebreak='true'>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>Basic</mi>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi>Cn</mi>
        <mo>=</mo>
        <mo stretchy='false'>(</mo>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mi mathvariant='italic' fontfamily='Times New Roman' mathsize = '11pt'>2</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathvariant='italic' fontfamily='Times New Roman' mathsize = '11pt'>0</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>3</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>&lowast;</mo>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>.</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>also</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>En</mi>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>pqrs</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>s</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>=</mo>
        <mi mathsize = '11pt'>pq</mi>
        <mo mathsize = '11pt'>=</mo>
        <mi mathsize = '11pt'>rs</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>s</mi>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>xyw</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>w</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>&lowast;</mo>
        <mi mathsize = '11pt'>w</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>w</mi>
        <mo mathsize = '11pt'>=</mo>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>gnp</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>4</mn>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>Relations</mi>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pqrs</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>xyw</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pr</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>qs</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>xyw</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>qr</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>ps</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pqrs</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Triangle</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>q</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>xyw</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Cn</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>points</mi>
        <mo mathsize = '11pt'>.</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>xy</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>w</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>wy</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>xyw</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>x</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>w</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Triangle</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>2</mn>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>y</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>h</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '14pt'>&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;&nbsp;</mtext>
        <mi mathsize = '11pt'>h</mi>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>h</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>y</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&plus;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>2</mn>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>y</mi>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>Cn</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Point</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>equivalence</mi>
        <mo mathsize = '11pt'>:</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>a</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>b</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>a</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>&lowast;</mo>
        <mi mathsize = '11pt'>b</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>a</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>c</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>d</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>c</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>&lowast;</mo>
        <mi mathsize = '11pt'>d</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>c</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pqrs</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>4</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>points</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>curve</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Cn</mi>
        <mo mathsize = '11pt'>:</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>pr</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pr</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>qs</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>qs</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>qr</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>qr</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>P</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>ps</mi>
        <mo mathsize = '11pt'>,</mo>
        <mi mathsize = '11pt'>ps</mi>
        <mo mathsize = '11pt'>&lowast;</mo>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pqrs</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>1</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>triad</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>squares</mi>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>q</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>r</mi>
        <mo mathsize = '11pt'>&plus;</mo>
        <mi mathsize = '11pt'>s</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>GNP</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>form</mi>
        <mo mathsize = '11pt'>:</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>=</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>4</mn>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>GNP</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Triangle</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Q</mi>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>sides</mi>
        <mtext mathvariant='bold' fontfamily='Times New Roman' mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mn mathsize = '11pt'>2</mn>
        <mi mathsize = '11pt'>np</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mo mathsize = '11pt'>&plus;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>4</mn>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>pg</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>GNP</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>Point</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mo mathsize = '11pt'>&minus;</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2,</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>pg</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mi mathsize = '11pt'>GNP</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt'>&minus;</mo>
        <mo mathsize = '11pt'>&gt;</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>xyw</mi>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>form</mi>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2,</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mi mathsize = '11pt'>g</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt'>,</mo>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>(</mo>
        <mi mathsize = '11pt'>n</mi>
        <mo mathsize = '11pt'>/</mo>
        <mi mathsize = '11pt'>p</mi>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>&circ;</mo>
        <mn mathsize = '11pt'>2</mn>
        <mtext mathsize = '11pt'>&nbsp;</mtext>
        <mo mathsize = '11pt' stretchy='false'>)</mo>
        <mo mathsize = '11pt'>.</mo>
      </mtd>
    </mtr>
    <mtr>
      <mtd>
        <mrow></mrow>
      </mtd>
    </mtr>
  </mtable>
</math>
