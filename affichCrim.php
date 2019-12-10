<?php

include '../core/criminelC.php';
$crim = new criminelC();
$listcrim = $crim->afficherCrim();
?>
<table border="2">
    <tr>
        <td>CIN</td>
        <td>Nom</td>
        <td>Prenom</td>
        <td>Date Naissance</td>
        <td>Nb Crimes</td>
        <td>Modifier</td>
    </tr>
<?php

foreach ($listcrim as $row)

{

    echo '
        <tr>
            <td>'.$row["cin"].'</td>
            <td>'.$row["nom"].'</td>
            <td>'.$row["prenom"].'</td>
            <td>'.$row["DateNaissance"].'</td>
            <td>'.$row["nbCrimes"].'</td>
            <td>
                <form action="modifierCrim.php" method="get">
                    <input type="hidden" id="cin" name="cin" value="'.$row["cin"].'">
                    <input type="hidden" id="nom" name="nom" value="'.$row["nom"].'">
                    <input type="hidden" id="pre" name="pre" value="'.$row["prenom"].'">
                    <input type="hidden" id="dat" name="dat" value="'.$row["DateNaissance"].'">
                    <input type="hidden" id="nbc" name="nbc" value="'.$row["nbCrimes"].'">
                    <input style="background: none; border: none; color: blue; text-decoration: underline;" type="submit" value="modifier">
                </form>
            </td>
        </tr>
    ';
}
?>
</table>
