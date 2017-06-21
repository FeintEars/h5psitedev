<style type="text/css">
  table {
    margin: 10px auto 0px;
  }
  td {
    padding: 5px 0px;
    font-size: 14px;
  }
  td.label {
    min-width: 70px;
    font-weight: bold;
  }
  td.value {
    color: #444;
  }
</style>
<table>
  <tr>
    <td class="label"><?php print t('URL'); ?>:</td>
    <td class="value"><?php print $url; ?></td>
  </tr>
  <tr>
    <td class="label"><?php print t('Key'); ?>:</td>
    <td class="value"><?php print $key; ?></td>
  </tr>
  <tr>
    <td class="label"><?php print t('Secret'); ?>:</td>
    <td class="value"><?php print $secret; ?></td>
  </tr>
</table>