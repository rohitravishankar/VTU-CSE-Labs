<?xml version="1.0" encoding="ISO-8859-1"?>                           
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
<body bgcolor="aqua">
<table border="1">
	<caption style="font-weight:bold;font-size:20px"> STUDENT Information</caption>
	<tr bgcolor="yellow">
		<th>USN</th>
		<th>NAME</th>
		<th>NAME OF COLLEGE</th>
		<th>BRANCH</th>
		<th>YEAR OF JOINING</th>
		<th>Email</th>
	</tr>
<xsl:for-each select="Student/Student_Info">
	<tr bgcolor="white">
	<td><xsl:value-of select="USN"/></td>
	<td><xsl:value-of select="NAME"/></td>
	<td><xsl:value-of select="COLLEGE"/></td>
	<td><xsl:value-of select="BRANCH"/></td>
	<td><xsl:value-of select="YOJ"/></td>
	<td><xsl:value-of select="Email"/></td>
	</tr>
</xsl:for-each>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
