<?php

    class Data{

        public  function get_message()
        {
            if (isset($_SESSION['flash'])):
                foreach ($_SESSION['flash'] as $key => $value): ?>
                    <div class="flash-<?= $key; ?>">
                    <span class="flash" onclick="this.parentElement.style.display = 'none';">&times;</span>
                    <p><?= $value; ?></p>
                    </div>
                <?php endforeach;
            unset($_SESSION['flash']);
            endif;
        }

        public function check_size($string, $size){
            if (strlen($string) <= $size)
                return TRUE;
            return false;
        }

        public function email($email){
            if (filter_var($email, FILTER_VALIDATE_EMAIL)){
                return true;
            return false;
        }
    }
}
