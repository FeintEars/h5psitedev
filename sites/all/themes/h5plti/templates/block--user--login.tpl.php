<div class="pull-right">
  <button data-toggle="collapse" data-target="#<?php print $block_html_id; ?>" class="pull-right"><?php print t('Log in'); ?></button>


  <div id="<?php print $block_html_id; ?>" class="collapse <?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($block->subject): ?>
    <h2<?php print $title_attributes; ?>><?php print $block->subject ?></h2>
  <?php endif;?>
    <?php print render($title_suffix); ?>
    <div class="content"<?php print $content_attributes; ?>>
      <?php print $content ?>
    </div>
  </div>


</div>