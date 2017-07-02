  <div id="page-wrapper"><div id="page">

    <div id="header"><div class="section clearfix">

      <?php if ($logo): ?>
        <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php print render($page['header']); ?>

    </div></div> <!-- /.section, /#header -->

    <?php if ($main_menu): ?>
      <div id="navigation"><div class="section">
        <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
      </div></div> <!-- /.section, /#navigation -->
    <?php endif; ?>

    <div id="main-wrapper"><div id="main" class="clearfix">

      <div id="content" class="column"><div class="section">
        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
        <?php print $messages; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php print render($page['content']); ?>
      </div></div> <!-- /.section, /#content -->

    </div></div> <!-- /#main, /#main-wrapper -->

    <div id="footer" class="footer">
      <div class="section">
        <div class="footerTop row">
          <div class="socialConnect col-xs-7">
            <h3 class="pull-left"><?php print t('Follow us on'); ?></h3>
            <?php print drupal_render($footer_menu); ?>
          </div>
        </div>
        <div class="br-line col-md-12"></div>
        <div class="footerMiddle row">
          <div class="col-md-1 col-xs-3">
            <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" class="logo"><img src="<?php print $base_path . drupal_get_path('theme', $GLOBALS['theme']); ?>/images/logo_footer.png" alt="GO1 logo"></a>
          </div>
          <div class="tagline col-md-5 col-xs-9">
            <?php print render($page['footer']); ?>
          </div>
        </div>
        <div class="br-line col-md-12"></div>
        <div class="footerBottom row">
          <div class="footerLinks col-sm-6">
            <?php print drupal_render($footer_menu2); ?>
          </div>
          <div class="copyright text-right col-sm-6">
            <i class="fa fa-copyright"></i> Copyright
            <span class="ng-binding"><?php print date('Y'); ?></span> GO1 - All Rights Reserved
          </div>
        </div>
      </div>
    </div>

  </div></div> <!-- /#page, /#page-wrapper -->
